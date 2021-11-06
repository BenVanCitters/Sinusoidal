import time
import math

def moddedSin():
	nanos_per_second = 1000000000
	cycle_len_seconds = math.pi*2
	mod_val = time.time_ns()%int(cycle_len_seconds*nanos_per_second)
	return sin(mod_val)
	
	
def sin_mod(offset_seconds: float, time_multiplier: float):
	nanos_per_millis
	nanos_per_second = 1000000000
	millis_per_second = 1000
	cycle_len_seconds = math.pi*2/time_multiplier
	mod_val = time.time_ns()%int(cycle_len_seconds*nanos_per_second)
	t_val = mod_val*1.0/nanos_per_second
	
	return sin(mod_val)