import cv2


capture = cv2.VideoCapture(1)
# capture.set(3,480)#宽
# capture.set(4,640)#高

print(capture.get(cv2.CAP_PROP_FRAME_WIDTH))
print(capture.get(cv2.CAP_PROP_FRAME_HEIGHT))
print(capture.get(cv2.CAP_PROP_FPS))
capture.grab()
# print(capture.get(cv2.CAP_PROP_FOURCC))
# while(capture.isOpened()):
# #     # 获取一帧
#     ret, frame = capture.read()
#     if ret:
#         print('OK')
# #     # # 将这帧转换为灰度图
# #     print(frame)
# #     # gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
# #     # print(frame.shape)
# #     # cv2.imshow('frame', frame)
#     if cv2.waitKey(1) == ord('q'):
#         break
capture.release()
cv2.waitKey(0)
# cv2.destroyAllWindow()