project('general_usage', 'cpp')
inc_dir = include_directories('include/3rdparty')
cpp = meson.get_compiler('cpp')
my_lib = cpp.find_library('__cerrors', dirs: 'F:/programming/C++/errors/examples/general_usage/bin')

my_lib_dep = declare_dependency(
    include_directories: inc_dir,
    dependencies: my_lib
)

executable('general_usag',
    'src/generalUsage.cpp',
    dependencies: my_lib_dep
)