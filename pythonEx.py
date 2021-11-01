import time
import math

def moddedSin():
	nanos_per_second = 1000000000
	mod_val = time.time_ns()%int(math.pi*2*nanos_per_second)
	return sin(mod_val)
	
	
