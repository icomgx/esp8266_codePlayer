import videoCut
import conv
import os

videos_src_path = "tw/"
# video_formats = [".MP4", ".MOV"]          我的数据集都是.mp4所以不需要进行分类判断
frames_save_path = "twcut/"
width = 128
height = 64
time_interval = 3

videoCut.video2frame(videos_src_path, frames_save_path, width, height, time_interval)
data = os.listdir('twcut/tw')
for dat in data:
    conv.conv2(f'twcut/tw/{dat}', f'twconv/{dat}')
data2 = os.listdir('twconv')
for dat2 in data2:
    conv.conv4(f'twconv/{dat2}', f'twconv2/{dat2}')
data3 = os.listdir('twconv2')
for dat3 in data3:
    conv.conv3(f'twconv2/{dat3}', f'twconv3/{dat3}')