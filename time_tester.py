import os

separator = os.sep

os.system("make")
for filename in os.listdir('test_scenarios_poisson'):
    os.system(f"main.e -m time_test -f test_scenarios_poisson{separator}{filename}")
    break

for filename in os.listdir('test_scenarios_uniform'):
    os.system(f"main.e -m time_test -f test_scenarios_uniform{separator}{filename}")
    break