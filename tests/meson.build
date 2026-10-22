gtest_dep = dependency('gtest_main', fallback : ['gtest', 'gtest_main_dep'])

cado_test_sources = files(
    'main.cpp',
    'test_errors.cpp',
    'errors/test_error.cpp',
)

cado_test_exe = executable('cado_tests',
  cado_test_sources,
  dependencies : [cado_dep, gtest_dep],
  include_directories : include_directories('.'),  # allow #include "errors/test_error.cpp" style if needed
)

test('cado_tests', cado_test_exe, protocol : 'gtest')
