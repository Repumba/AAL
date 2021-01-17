import os
import numpy as np

import shutil
import argparse

parser = argparse.ArgumentParser(description='list of the contents of the folder')

parser.add_argument('-n', '--nWorkers', action='store', default=[1000, 10000, 100000, 200000, 500000, 1000000], help='Number of workers')
parser.add_argument('-m', '--mCapacity', action='store', default=[2, 10], help='Capacity of the microwave')
parser.add_argument('-t', '--cookTime', action='store', default=[2, 10, 100], help='Unit time cooking')
parser.add_argument('-k','--kTests', action='store', default=3, help='Number of tests per instance')
parser.add_argument('-l', '--lambdas', action='store', default=[10, 100, 1000], help='Lambda values for Poisson distribution')
parser.add_argument('-d', '--disctibution', action='store', default=['poisson'], help='Distribution of coming moments [poisson, uniform]')

args = parser.parse_args()


# distributions = ['uniform', 'poisson']
poisson_lambdas = args.lambdas

workers_counts = {n_workers: args.kTests for n_workers in args.nWorkers}


microwave_capacities = args.mCapacity
unit_times_cooking = args.cookTime

distribution = args.distribution


def generate_poisson(folder_name):

    i = 0
    for n_workers, num_tests in workers_counts.items():

        for j in range(num_tests):
            
            for capacity in microwave_capacities:

                for time_cooking in unit_times_cooking:

                    for lambda_ in poisson_lambdas:
                        
                        with open(f"{folder_name}/poisson_test_{i}.txt", 'w') as test_file:
                            test_file.write(f'{n_workers} {capacity} {time_cooking} p \n')
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

                            test_file.write(f'{n_workers} {capacity} {time_cooking} u \n')
                            times = np.random.uniform(0, int(n_workers * np.random.uniform(10, 20)), size=n_workers)
                            # HERE WE GO AGAIN
                            times.sort()
                            final_string = " ".join([str(int(item)) for item in times]) + "\n"
                            test_file.write(final_string)
                        print(i)
                        i += 1


sep = os.sep

if 'test_scenarios_poisson' in os.listdir():
    shutil.rmtree(os.getcwd() + f'{sep}test_scenarios_poisson', ignore_errors=True)

if 'test_scenarios_uniform' in os.listdir():
    shutil.rmtree(os.getcwd() + f'{sep}test_scenarios_uniform', ignore_errors=True)


if 'poisson' in distribution:

    if not 'test_scenarios_poisson' in os.listdir():
        os.mkdir('test_scenarios_poisson')
    
    generate_poisson("test_scenarios_poisson")
    

if 'uniform' in distribution:

    if not 'test_scenarios_uniform' in os.listdir():
        os.mkdir('test_scenarios_uniform')

    generate_usual_tasks("test_scenarios_uniform")