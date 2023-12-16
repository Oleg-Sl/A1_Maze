import os


def generate_include_guard(project_name, file_path):
    relative_path = os.path.relpath(file_path, os.path.dirname(__file__))
    formatted_path = relative_path.replace(
        os.path.sep, '_').replace('.', '_').upper()
    include_guard = f'__{project_name.upper()}_{formatted_path}__'
    return include_guard


def process_header_file(project_name, header_file):
    with open(header_file, 'r') as file:
        lines = file.readlines()

    ifndef_found = False
    if lines[0].startswith('#ifndef') and lines[-1].startswith('#endif'):
        ifndef_found = True

    if not ifndef_found:
        ifndef_line = f'#ifndef {generate_include_guard(project_name, header_file)}\n'
        define_line = f'#define {generate_include_guard(project_name, header_file)}\n'
        endif_line = f'#endif  // {generate_include_guard(project_name, header_file)}\n'

        lines.insert(0, ifndef_line)
        lines.insert(1, define_line)
        lines.append(endif_line)

        with open(header_file, 'w') as file:
            file.writelines(lines)
        print(f'Include guard added for {header_file}')
    else:
        lines[0] = f'#ifndef {generate_include_guard(project_name, header_file)}\n'
        lines[1] = f'#define {generate_include_guard(project_name, header_file)}\n'
        lines[-1] = f'#endif  // {generate_include_guard(project_name, header_file)}'

        with open(header_file, 'w') as file:
            file.writelines(lines)
        print(f'Include guard updated for {header_file}')


def process_project(project_name):
    for root, dirs, files in os.walk(os.getcwd()):
        for file in files:
            if file.endswith('.h'):
                header_file = os.path.join(root, file)
                process_header_file(project_name, header_file)


if __name__ == "__main__":
    project_name = input("Введите имя проекта: ")
    process_project(project_name)
