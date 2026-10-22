# errors
## Errors just like in go
Header only library
build-tests:

```shell
meson wrap install gtest
meson setup build
meson compile -c build
```


### Examples

#### Default usage
```cpp
#include <cado/errors/errors.hpp>
#include <sstream>
#include <cstdio>
using namesapce cado;
using errors::Error;

bool validate_negative(int a, Error& err){
    if (a >= 0){
        err = errors::new_e("failed to validate, value is positive");
        return false;
    }
    if (a <= -20  && a >= -10) {
        return false;
    }
    return true;
}

int main(){
    Error err;
    bool res = validate_negative(10, err);
    if (err != errors::null){
        std::printf("%s", err->what().c_str());
        // >> "failed to validate, value is positive";
    }
    return 0;
}
```

#### Format usage
```cpp
#include <cado/errors/errors.hpp>
#include <sstream>
#include <cstdio>
using namesapce cado;
using errors::Error;

bool validate_negative(int a, Error& err){
    if (a >= 0){
        err = errors::format("reason: %s, value: %d","failed to validate, value is positive", a);
        return false;
    }
    if (a <= -20  && a >= -10) {
        return false;
    }
    return true;
}

int main(){
    Error err;
    bool res = validate_negative(10, err);
    if (err != errors::null){
        std::printf("%s", err->what().c_str());
        // >> "reason: failed to validate, value: 10"
    }
    return 0;
}
```

#### Sentinel usage
```cpp
#include <cado/errors/errors.hpp>
#include <sstream>
#include <cstdio>
using namesapce cado;
using errors::Error;

Error ErrValidateNegative = errors::new_e("failed to validate, value is positive");

bool validate_negative(int a, Error& err){
    if (a >= 0){
        err = ErrValidateNegative
        return false;
    }
    if (a <= -20  && a >= -10) {
        return false;
    }
    return true;
}

int main(){
    Error err;
    bool res = validate_negative(10, err);
    if (err != errors::null){
        
        std::printf("%d, error: %s", errors::is(err, ErrValidateNegative), err->what().c_str());
        // >> "1, error: failed to validate, value is positive"
    }
    return 0;
}
```

#### User error
```cpp
#include <cado/errors/errors.hpp>
#include <sstream>
#include <cstdio>
using namesapce cado;
using errors::Error;

class NegativeValidationError : public errors::BaseError {
    public:
        NegativeValidationError(const std::string& var_name) : errors::BaseError("failed to validate negative"), var_name_(var_name){};
        std::string what() const override {
            std::stringstream ss;
            ss << this->msg_ << " variable " << var_name_ << " is not negative" << std::endl;
            return ss.str(); 
        } 
    private:
        const std::string var_name_;
}

Error ErrNegativeValidationVarA = Error{new NegativeValidationError("a")}; 

bool validate_negative(int a, Error& err){
    if (a >= 0){
        err = ErrNegativeValidationVarA;
        return false;
    }
    if (a <= -20  && a >= -10) {
        return false;
    }
    return true;
}

int main(){
    Error err;
    bool res = validate_negative(10, err);
    if (err != errors::null){
        std::printf("%d, error: %s", errors::is(err, ErrNegativeValidationVarA), err->what().c_str());
        // >> "1, error: failed to validate negative variable a is not negative"
    }
    return 0;
}
```
