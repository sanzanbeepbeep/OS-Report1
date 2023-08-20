import random
import subprocess
import time

def timeTaken ( cmd ):
    start = time.time()
    with open( "input.txt", "r" ) as infile:
        result = subprocess.run( cmd, stdin=infile, capture_output=True, text=True )
    end = time.time()
    return ( end - start ) 

# Number of random numbers to generate
num_numbers = int(input("Enter the number of random numbers( N ) : "))

# Generate the random numbers
random.seed(random.randint(0, 1000))
random_numbers = [random.randint(0, 255) for _ in range(num_numbers)]

# Write the numbers and the average to input.txt
with open('input.txt', 'w') as f:
    f.write(str(num_numbers) + '\n')
    for number in random_numbers:
        f.write(str(number) + '\n')
        
# Compile the C++ code  
fileNoThread = "./averageNoThread"
fileThread = "./averagepx"  
    
# Call function to calculate time taken
print(f"Time of no thread: { timeTaken( fileNoThread ) }")
print(f"Time of thread: { timeTaken( fileThread ) }")
