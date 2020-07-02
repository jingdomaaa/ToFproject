import numpy as np
import imageio

rawfile = np.fromfile('D:/Project/ToFDemo/x86_Release_0304/Release/initial_data_01.raw', dtype=np.float32)
print(rawfile.shape)