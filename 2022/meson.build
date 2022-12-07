project('advent-of-code', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++20'])

fs = import('fs')

N_DAYS = 4

conf_data = configuration_data()

decls = ''

foreach i : range(1, N_DAYS)
  name = 'day' + i.to_string()

  example_input = fs.read('inputs/@0@-example.txt'.format(name))
  decls += 'const std::string DAY@0@_EXAMPLE_INPUT(R"STR(@1@)STR");\n'.format(i, example_input)

  input = fs.read('inputs/@0@.txt'.format(name))
  decls += 'const std::string DAY@0@_INPUT(R"STR(@1@)STR");\n'.format(i, input)
endforeach

conf_data.set('input-decls', decls)

configure_file(input : 'config.h.in',
  output : 'config.h',
  configuration : conf_data)

configuration_inc = include_directories('.')

foreach i : range(1, N_DAYS)
  exe_name = 'day' + i.to_string()
  exe = executable(exe_name, ['src/' + exe_name + '.cpp'],
    include_directories : configuration_inc)
  test('basic', exe) # TODO(smolck): Is this even necessary?
endforeach
