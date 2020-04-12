import matplotlib.pyplot as plt
import numpy as np
from createfile import write_to_header_file

N = 64
x1 = np.geomspace(start=30, stop=110,  num=N, endpoint=True, dtype=int)
x2 = np.linspace(start=30, stop=110, num=N, endpoint=True, dtype=int)
#x2 = np.geomspace(start=1024, stop=48,  num=N, endpoint=True, dtype=int)
#x3 = np.concatenate([x1, x2])
#y = np.zeros(N)
y = np.zeros(N)
plt.plot(x1, y, 'o')
#plt.plot(x2, y, 'o')

#plt.ylim([-0.5, 1])
for item in x1:
    print(item)
plt.show()

write_to_header_file(x1, "fade_log_seq", "fade_log_seq.h")
write_to_header_file(x2, "fade_lin_seq", "fade_lin_seq.h")