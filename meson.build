project('cado', 'cpp',
  version : '0.1.0',
  default_options : ['cpp_std=c++17'])
cado_inc = include_directories('include')
cado_dep = declare_dependency(
  include_directories : cado_inc,
)
if not meson.is_subproject()
  subdir('tests')
endif
