#!/bin/bash

#SBATCH -J parallel16               # Job name
#SBATCH -o parallel16.%j.out         # Name of stdout output file (%j expands to jobId)
#SBATCH -c 16                  # Number of cores per task
#SBATCH -t 00:30:00           # Run time (hh:mm:ss) - 0.5 hours

# Set OMP_NUM_THREADS to the same value as -c
# with a fallback in case it isn't set.
# SLURM_CPUS_PER_TASK is set to the value of -c, 
# but only if -c is explicitly set
if [ -n "$SLURM_CPUS_PER_TASK" ]; then
  omp_threads=$SLURM_CPUS_PER_TASK
else
  omp_threads=1
fi
export OMP_NUM_THREADS=$omp_threads

# Launch OMP-based executable

prog=$1
arg1=$2

srun ./${prog} ${arg1}

