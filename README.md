# Camera_Test

## SimpleSample

- SimpleSample是工业相机的C++实例文件，我修改了一些SDK文件以使用OpenCV对摄像头图像进行获取 (line 1576)
- 使用方法：在SimpleSample文件夹下运行sudo make编译后 执行./runSample.sh命令运行
- 问题：line 1591 使用cvCreateImageHeader()前需要将图像位深改为8bit，否则后面cvShowImage会报错：segmentation fault缓冲区溢出
- [参考网页:OpenCV 处理内存中的图像数据](https://blog.csdn.net/b5w2p0/article/details/10973071)

## RP_Infantry_Plus-master

- RP_Infantry_Plus-master是深大的自瞄代码，和我们用的是同款相机

## 曝光模式&曝光时间（us）（建议10000us）

|曝光模式|含义|
|:-|:-|
|Off|手动调节曝光时间（曝光量）|
|Once|单次设定曝光时间（不可手动调节）？？？|
|Continuous|连续曝光时间（不可手动调节）？？？|

- 光圈：光圈控制光线进入的通路的大小,光圈越大,则单位时间的光通量越大,光圈越小,则单位时间的光通量越小
- 曝光时间：也就是快门速度，快门速度和光圈大小是互补的。
- 曝光：曝光对照片质量的影响很大,如果曝光过度,则照片过亮,失去图像细节;如果曝光不足,则照片过暗,同样会失去图像细节
- 不过曝的前提下，增加曝光时间可以增加信噪比，使图像清晰。对于很弱的信号，曝光也不能无限增加，因为随着曝光时间增加，噪音也会积累。

## 增益（1~32；建议1）

- 增益：经过双采样之后的模拟信号的放大增益。由于在对图像信号进行放大的过程中同时也会放大噪声信号,因此通常把放大器增益设为最小。
- 工业相机内有一个将来自 CCD 的信号放大到可以使用水准的视频放大器，其放大即增益，等效于有较高的灵敏度，然而在亮光照的环境下放大器将过载，此时的噪点也会比较明显，使视频信号畸变。
- 相机通常具有一个对传感器的信号进行放大的视频放大器，其放大倍数称为增益。若放大器的增益保持不变，则在高亮度环境下将使视频信号饱合。利用相机的自动增益控制（AGC）电路可以随着环境内外照度的变化自动的调整放大器的增益，从而可以使相机能够在较大的光照范围内工作。teo摄像机能根据实时照度，自动提高摄像机的增益调节亮度，从而在低照度环境下仍能显示较好的图像。
- 增益一般只是在信号弱，但不想增加曝光时间的情况下使用。
- 曝光和增益是直接控制传感器(CCD/CMOS)上读出来的数据，是要优先调节的，以调节曝光时间为主。在不过曝的前提下，增加曝光时间可以增加信噪比，使图像清晰。当然，对于很弱的信号，曝光也不能无限增加，因为随着曝光时间的增加，噪音也会积累， 曝光补偿就是增加拍摄时的曝光量。
增益一般只是在信号弱，但不想增加曝光时间的情况下使用，一般相机增益都产生很大噪音。工业相机在不同增益时图像的成像质量不一样，增益越小，噪点越小；增益越大，噪点越多，特别是在暗处。数码相机的ISO就是这里说的增益，增大ISO，是增加感光器件对光的灵敏度。高感光度对低光照灵敏，同时对噪杂信号也灵敏，信噪比小，所以高感光度噪点也多(可利用图片软件的降噪功能减轻或去除)。
- 调节亮度增益说白了就是改变ISO，改变CMOS传感器的感光性能，但是会影响到画质。调节曝光补偿则是为了改变快门速度，不改变ISO不会影响画质。

## 伽马（1~4）

- 在图像处理中，将漂白(相机过曝)的图片或者过暗(曝光不足)的图片，进行修正
- 按幂函数对亮度值重新分布，伽玛就是指数。伽玛大于1使亮的更亮暗的更暗，可以抹掉一些弱信号；小于1则相反可以让较弱信号显示出来
- gamma值小于1时，会拉伸图像中灰度级较低的区域，同时会压缩灰度级较高的部分,提高图像对比度
- gamma值大于1时，会拉伸图像中灰度级较高的区域，同时会压缩灰度级较低的部分

## 降噪(0~100)

- 减少噪点
- 降噪功能是指针对噪点进行优化和消除的功能。噪点 主要是指CCD（CMOS）【CCD（电荷耦合器件）芯片和CMOS（互补金属氧化物半导体）芯片都将光线（光子）转换成电子信号（电子）。】将光线作为接收信号并输出的过程中所产生的图像中的粗糙部分，也指图像中不该出现的外来像素和伪色块，通常由电子干扰产生。
- 长时间曝光产生噪点，这种现象主要大部分出现在使用低ISO拍摄夜景，在图像的黑暗的夜空中，出现了一些杂乱的亮点。可以说其原因是由于处理器无法处理较慢的快门速度所带来的巨大的工作量，致使一些特定的像素失去控制而造成的。为了防止产生这种图像噪音，部分数码相机中配备了被称为"降噪"的功能。
如果使用降噪功能，在记录图像之前就会利用数字处理方法来消除图像噪音，因此在保存完毕以前就需要花费一点额外的时间。但随着降噪功能的开启，画面细节会损失。
- 紫边一般是由镜头原因造成，与降噪和感光元件关系不大。

## 锐度(0~100)

- 锐度指的是增加分割画面区域的边缘线周边的对比度，从而达到刻痕的效果，使得内容更加锐利。锐化仅会影响少部分边缘像素的对比度，整个画面并不会受到大量的影响
- 对比度：图像最亮和最暗之间的区域之间的比率，比值越大，从黑到白的渐变层次就越多，从而色彩表现越丰富。对比度对视觉效果的影响非常关键，一般来说对比度越大，图像越清晰醒目，色彩也越鲜明艳丽；而对比度小，则会让整个画面都灰蒙蒙的。高对比度对于图像的清晰度、细节表现、灰度层次表现都有很大帮助。对比度越高图像效果越好，色彩会更饱和，反之对比度低则画面会显得模糊，色彩也不鲜明。对比度指的是拉扯整个图像的曝光水平，让亮的地方更亮，暗的地方更暗

## 亮度(0~100;默认50)

- 调整图像亮度
- [学会理解相机中的亮度直方图，能够得到更加准确的曝光](http://baijiahao.baidu.com/s?id=1596739433503109140&wfr=spider&for=pc)

## 数字位移(0~4)

- 利用相机拍摄变形前后被测物体表面的数字散斑图像，再通过匹配变形前后数字散斑图像中的对应图像子区获得被测物体表面哥点的位移
- 物体变形前后，其表面上的几何点的移动产生了位移，通过相关算法，确定物体变形前后对应的几何点，可以得到位移
- 在变形前后的图像上，各取大小为mxm的子区域，计算相关系数C，改变u，V的值，即在变形前后的图像上移动的子区域，可以得到不同的C值，使得C取得最大值的u和v，即是子区域中心的位移，该公式求得的是物体表面的整像素位移值

## 白平衡(off/once/continous)

- 白平衡（White Balance)是彩色相机中采用的技术，白平衡是对红、绿、蓝三个分量的平衡，以使相机能反映实际景物真实颜色。由于光敏元件在不同的光照条件下RGB 三个分量的输出是不平衡的，从而会差生图像在色彩上的失真，偏蓝或者偏红，因此需要白平衡来还原图像的色彩

## DeviceControl

- DevivelinkThroughputLimitMode ：设备链接穿透输出限制模式（状态：off）图像的传输设置
- DevivelinkThroughputLimit:(400,000,000)

摄像机输出的视频信号必须达到电视传输规定的标准电平，即,为了能在不同的景物照度条件下都能输出的标准视频信号，必须使放大器的增益能够在较大的范围内进行调节。这种增益调节通常都是通过检测视频信号的平均电平而自动完成的，实现此功能的电路称为自动增益控制电路，简称AGC电路。具有AGC功能的摄像机，在低照度时的灵敏度会有所提高，但此时的噪点也会比较明显。这是由于信号和噪声被同时放大的缘故

## 参考资料

- [工业视觉 四 曝光与增益 、伽马、饱和度、对比度、锐度、黑电平](https://blog.csdn.net/qq_20848403/article/details/81198540)
- [工业相机 常用参数](https://blog.csdn.net/caojinpei123/article/details/100877401)
- [视觉工程师必须知道的工业相机50问，绝对干货！（转载）](https://www.cnblogs.com/fredliu/p/10030455.html)
- [相机曝光三要素的作用](http://ask.zol.com.cn/x/12708932.html)
