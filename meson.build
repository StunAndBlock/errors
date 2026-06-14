project('__cerrors', 'cpp',
	version: '0.1.0',
	default_options:[
		'cpp_std=c++17',
		'default_library=both',
		'buildtype=release'
	])

cado_errors_lib = library('__cerrors',
    sources: [
        'src/errors/Error.cpp',
	'src/errors/Errors.cpp'
	],
    include_directories: include_directories('./include'),
    cpp_args: ['-DCADO_ERRORS_EXPORT'],
    name_prefix: '',
    install: true,
)

cado_errors_dep = declare_dependency(
    include_directories: include_directories('./include'),
    link_with: cado_errors_lib
)

install_headers(
	'include/cado/errors/Error.hpp',	
	'include/cado/errors/Errors.hpp',
	'include/cado/errors/Export.hpp',
	subdir: 'include/cado/errors'
)