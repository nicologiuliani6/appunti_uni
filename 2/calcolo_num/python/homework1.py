import numpy as np
import matplotlib.pyplot as plt
import bisezione
import punto_fisso
import newton

if __name__ == "__main__":
  #es1
  g1 = lambda x : (np.log(x+1))
  f1 = lambda x : (np.log(x+1)-x*(g1(x)))
  df1 = lambda x: (1 - x) / (x + 1) - np.log(x + 1) 
  a1 = 0
  b1 = 2
  radice1, iterazioni1 = bisezione.bisezione(f1, a1, b1)
  print(f"1) BISEZIONE= {radice1:0.4f}, ITERAZIONI= {iterazioni1}")
  radice2, iterazioni2 = punto_fisso.punto_fisso(g1, a1, b1)
  print(f"1) PUNTO FISSO= {radice2:0.4f}, ITERAZIONI= {iterazioni2}")
  radice3, iterazioni3 = newton.newton(f1, df1, 0.5)
  print(f"1) NETWON= {radice3:0.4f}, ITERAZIONI= {iterazioni3}\n")

  #es2
  g2 = lambda x: np.cos(x)**0.5
  f2 = lambda x: x**2 - np.cos(x)*g2(x)
  df2 = lambda x: 2*x + np.sin(x)*np.sqrt(np.cos(x)) + (np.cos(x)*np.sin(x)) / (2*np.sqrt(np.cos(x)))
  a2 = 0
  b2 = 1
  radice1, iterazioni1 = bisezione.bisezione(f2, a2, b2)
  print(f"2) BISEZIONE= {radice1:0.4f}, ITERAZIONI= {iterazioni1}")
  radice2, iterazioni2 = punto_fisso.punto_fisso(g2, a2, b2)
  print(f"2) PUNTO FISSO= {radice2:0.4f}, ITERAZIONI= {iterazioni2}")
  radice3, iterazioni3 = newton.newton(f2, df2, 0.5)
  print(f"2) NETWON= {radice3:0.4f}, ITERAZIONI= {iterazioni3}\n")

  #es3
  g3 = lambda x: 2*np.sin(x)
  f3 = lambda x: np.sin(x) - x*np.sin(x)
  df3 = lambda x: (1 - x)*np.cos(x) - np.sin(x)
  a3 = -1
  b3 = 1
  radice1, iterazioni1 = bisezione.bisezione(f3, a3, b3)
  print(f"3) BISEZIONE= {radice1:0.4f}, ITERAZIONI= {iterazioni1}")
  radice2, iterazioni2 = punto_fisso.punto_fisso(g3, a3, b3)
  print(f"3) PUNTO FISSO= {radice2:0.4f}, ITERAZIONI= {iterazioni2}")
  radice3, iterazioni3 = newton.newton(f3, df3, 0.5)
  print(f"3) NETWON= {radice3:0.4f}, ITERAZIONI= {iterazioni3}\n")

  #es4
  g4 = lambda x: (1/3) * np.e**x
  f4 = lambda x: np.e**x - 3*x * g4(x)
  df4 = lambda x: np.e**x - 3 * ( g4(x) + x * (1/3) * np.e**x )
  a4 = -1
  b4 = 1
  radice1, iterazioni1 = bisezione.bisezione(f4, a4, b4)
  print(f"4) BISEZIONE= {radice1:0.4f}, ITERAZIONI= {iterazioni1}")
  radice2, iterazioni2 = punto_fisso.punto_fisso(g4, a4, b4)
  print(f"4) PUNTO FISSO= {radice2:0.4f}, ITERAZIONI= {iterazioni2}")
  radice3, iterazioni3 = newton.newton(f4, df4, 0.5)
  print(f"4) NETWON= {radice3:0.4f}, ITERAZIONI= {iterazioni3}\n")
  """
  x = np.linspace(-10, 10)
  plt.axhline(0, color='k')            # linea orizzontale a y=0
  plt.plot(x, f4(x), 'b', label='')
  plt.plot(radice1, f4(radice1), 'ro')
  plt.plot(radice2, f4(radice2), 'go')
  plt.plot(radice3, f4(radice3), 'yo')
  plt.show()
  """
  
  
