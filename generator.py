import os
import numpy as np

import shutil

# distributions = ['uniform', 'poisson']
poisson_lambdas = [1, 10, 100]

workers_counts = {
    1000000: 3,
    500000: 3,
    200000: 3,
    100000: 3,
    10000: 3,
    1000: 3,
}


microwave_capacities = [2, 10]
unit_times_cooking = [10, 100, 1000]    # Don't think this gonna affect much



if 'test_scenarios_poisson' in os.listdir():
    shutil.rmtree(os.getcwd() + '\\test_scenarios_poisson', ignore_errors=True)

if 'test_scenarios_uniform' in os.listdir():
    shutil.rmtree(os.getcwd() + 'test_scenarios_uniform', ignore_errors=True)

if not 'test_scenarios_poisson' in os.listdir():
    os.mkdir('test_scenarios_poisson')

if not 'test_scenarios_uniform' in os.listdir():
    os.mkdir('test_scenarios_uniform')

i = 0
def generate_poisson(folder_name):
# generating 
    i = 0
    for n_workers, num_tests in workers_counts.items():

        for j in range(num_tests):
            
            for capacity in microwave_capacities:

                for time_cooking in unit_times_cooking:

                    for lambda_ in poisson_lambdas:
                        
                        with open(f"{folder_name}/poisson_test_{i}.txt", 'w') as test_file:
                            test_file.write(f'{n_workers} {capacity} {time_cooking}\n')
                            times = np.random.poisson(lambda_, n_workers)
                            final_string = ""
                            current_time = 0
                            for value in times:
                                current_time += value
                                final_string += f"{current_time} "
                            final_string = final_string[:-1] + "\n"
                            test_file.write(final_string)
                        print(i)
                        i += 1




def generate_usual_tasks(folder_name):

    i = 0
    for n_workers, num_tests in workers_counts.items():

        for j in range(num_tests):
            
            for capacity in microwave_capacities:

                for time_cooking in unit_times_cooking:

                    for lambda_ in poisson_lambdas:
                        
                        with open(f"{folder_name}/uniform_test_{i}.txt", 'w') as test_file:

                            test_file.write(f'{n_workers} {capacity} {time_cooking}\n')
                            times = np.random.uniform(0, n_workers * 10, size=n_workers)
                            # HERE WE GO AGAIN
                            times.sort()
                            final_string = " ".join([str(int(item)) for item in times]) + "\n"
                            test_file.write(final_string)
                        print(i)
                        i += 1

generate_poisson("test_scenarios_poisson")
print("Inserted Poisson Scenarios!")
generate_usual_tasks("test_scenarios_uniform")