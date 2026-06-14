#ifndef CADO_ERRORS_EXPORT_HPP_
#define CADO_ERRORS_EXPORT_HPP_

#pragma once

#ifdef _WIN32
    #ifdef CADO_ERRORS_EXPORT
        #define CADO_API __declspec(dllexport)
    #else
        #define CADO_API __declspec(dllimport)
    #endif
#else
    #define CADO_API __attribute__((visibility("default")))
#endif


#endif //!CADO_ERRORS_EXPORT_HPP_
