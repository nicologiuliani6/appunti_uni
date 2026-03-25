import numpy as np

arr = np.logspace(1, 8, base=10)  # 20 valori da 10^1 a 10^17

for m in arr:
  e = (1 + 1/m)**m
  print(f"e= {e:.16f}")
