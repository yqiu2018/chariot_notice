# 智能战车 DIY 活动

欢迎大家参与一起 DIY 智能战车活动，本次活动的成果将是制作出一辆属于自己的智能战车，活动过程中，会涉及到方方面面的知识，需要大家持续学习。相关的资料全部开源/开放。

## 功能要求

### 基本功能：遥控智能车 

* 本功能需要完成底盘运动控制系统，进而通过底盘的电机控制战车能够前进、后退、左转、右转、旋转、加速、减速！并实现通过编码器反馈速度，通过PID算法控制速度。战车可以支持不同类型的底盘，如：麦克纳姆轮、后轮差速驱动、前轮舵机转向，后轮动力驱动等等。也支持通过PWM或者CAN进行控制的电机！

* 除此之外，还需要实现遥控系统，以达成使用遥控器对战车进行遥控指挥！我们可以支持大多数遥控器，比如：PS2遥控、航模遥控器、手机或PC通过Wi-Fi遥控！

### 高级功能：云台和射击功能 、自动识别目标


* 完成这一部分，参与者也许会遇到一些挑战，但只有遇到过挑战才能体会“会当凌绝顶”的快意不是吗？我们需要完成射击系统，通过二轴云台控制射击装置的运动，实现射击装置可上下、左右转动，以瞄准射击目标。支持红外射击（通过红外激光进行发射）、水弹射击（通过拨弹轮和摩擦轮控制射击，对机械要求高），以上射击方式可自选。我们将使用LED灯管或者LCD屏标识血量，被射中的战车可以显示失血。并实现战车在射击和被击中都会发出声音！

* 为了避免沙雕战车敌我不分的情况，我们还需要完成目标识别系统。这里需要通过摄像头进行图像采集，使用机器视觉对采集的图像进行目标识别，然后控制射击系统对目标进行射击！

### 扩展功能：自由发挥

* 平衡车、履带车、避障、路径规划、竞速、图像视觉、语音等

## 时间安排 第一阶段  4  周

### 第一周 

1. 第一阶段硬件环境准备，控制板、车模底盘及其他配件
  * 控制板，自行选择，如 IoT Board，Robomaster，imxRT 等，官方使用 IoT Board；
    * https://item.taobao.com/item.htm?id=583527145598
    * https://github.com/RT-Thread/IoT_Board
  * 底盘自行选择，参考底盘：
    * https://item.taobao.com/item.htm?spm=a1z0d.6639537.1997196601.220.61187484ephkBL&id=35831296664
    * https://item.taobao.com/item.htm?spm=a1z10.5-c-s.w4002-16331967916.36.26fd22bfp3xr3H&id=550450598518
    * https://item.taobao.com/item.htm?spm=2013.1.20160405.12.afaf11b7lLmKUu&scm=1007.13066.127283.0&id=579913504272
  * 电机驱动板参考
    * https://item.taobao.com/item.htm?spm=a1z0d.6639537.1997196601.255.61187484ephkBL&id=578999575475
  * 遥控器自选，PS2 / 航模遥控 / 大疆遥控器，参考：
    * https://item.taobao.com/item.htm?spm=a1z0d.6639537.1997196601.202.61187484ephkBL&id=536581090144

2. 软件项目准备
  * 熟悉 Git、Github、Markdown
  * 参考 https://github.com/yqiu2018/pandora_robot 创建自己的 github 仓库
  * 向 https://github.com/yqiu2018/chariot_notice/blob/master/README.md 提交 pr, 登记信息

3. 在控制板上移植 RT-Thread,FinSH 能正常运行
  * 使用 RT-Thread 3.1.3 版本，下载地址：https://pan.baidu.com/s/1mgIAyWo#list/path=%2Fsharelink4264488348-458281830578469%2FRT-Thread%E5%8F%91%E5%B8%83&parentPath=%2Fsharelink4264488348-458281830578469
  * 入门资料： https://www.rt-thread.org/document/site/
  * API手册：https://www.rt-thread.org/document/api/index.html
  * STM32 运行：https://github.com/RT-Thread/rt-thread/tree/master/bsp/stm32
  * ENV工具：ENV工具可以通过以下链接获取：https://pan.baidu.com/s/1cg28rk#list/path=%2F

4. PWM 驱动或者CAN 驱动调试成功
  * 参考 https://www.rt-thread.org/document/site/programming-manual/device/pwm/pwm/

  完成文档报告例如：“[一起 DIY 智能战车]软硬件环境准备”。介绍软硬件环境的准备过程，提交到自己的 github 仓库，并发布到至少一个论坛；

###  第二周

1. 实现智能车开环控制功能
  * 阅读 RT-Robot 源码
  * 阅读 RT-Robot 设计文档
  * 实现智能车的开环控制功能，智能车能前进/后退/左转/右转

  完成文档报告例如：“[一起 DIY 智能战车]创建智能车应用，实现开环控制”。提交到自己的 github 仓库，并发布到至少一个论坛；

###  第三周

1. 实现遥控器控制功能
  * 控制板如有 Wi-Fi 功能，先可使用 Wi-Fi 实现 Telnet 进行控制
  * 其他的可以使用 PS2 / 航模 / 大疆遥控器进行控制

  完成文档报告例如：“[一起 DIY 智能战车]创建智能车应用，实现遥控器控制”。提交到自己的 github 仓库，并发布到至少一个论坛；

###  第四周

1. 实现编码器驱动或者其他测速驱动
2. 调试 PID 控制算法，实现闭环控制

 完成文档报告例如：“[一起 DIY 智能战车]创建智能车应用，实现闭环控制”。提交到自己的 github 仓库，并发布到至少一个论坛；

## 第二阶段

### 待安排

## 奖励

项目完成后会对大家最终完成的作品进行评奖，标准如下：

* 过程 50%：每周的文档报告质量；任务完成及时性；
* 结果 50%：最终作品的功能、性能；

* 优秀作品将获得 1000 元现金奖励
* 本次报名活动时缴纳100元活动经费，在实现基本功能智能遥控小车后退还，未完成者的费用将会作为优秀作品选手的额外奖励；

## 要求
  * 请按时完成任务，原则上第一阶段完成时间不超过6周；
  * 本次活动需花费较多时间，请合理安排时间。
  * 请在微信群中多沟通，大家互相帮助，一起 DIY，一起加油！

## 智能车项目列表

| 队伍名    | 项目名           | Github 地址                                 |
| --------- | ---------------- | ------------------------------------------- |
| 狂暴战车  | 潘多拉差速智能车 | https://github.com/yqiu2018/pandora_robot/  |
| MiniDream | IFRobot          | https://github.com/leazer/MiniDream_IFRobot |
| 橘子战队  | juzi_robot       | https://github.com/shenjinpeng/juzi_robot   |
| 鲲鹏战队  | roc_robot        | https://github.com/Eronwu/roc_robot         |
| 影        | robo_car         | https://github.com/lixing3204/rm_car        |
| 牛奔奔战队 | miaomiao_car     | https://github.com/XiaojieFan/miaomiao_car  |
| SnowStorm战队 | snowstorm_car         | https://github.com/bluesky-ryan/snowstorm_car.git |
| 1+1战队   | 1+1战队的小车     | https://github.com/271359695/xiaoche_car.git  |
|我是田甜做梦都想得到的男人|SLAMUGV |https://github.com/HE585858/SLAMUGV.git |
| 中天战队 | 潘多拉麦克纳姆智能车 | https://github.com/sundm75/pandora_zhongtian_car |
| 滑稽小队 | funny_car | https://github.com/iamluoyijie/funny_car |
| 妖魔战队 | 差速三轮车  | https://github.com/yaojinrun/yaomo_car |
| KeepAhead战舰 | Seven_Robot         | https://github.com/yanchunqing2010/Seven_Robot |
| ONE_T战队 | 亚博智能战车        | https://github.com/wang84947/4wdcar_stm32103|
| air  |   kingcobra_car   | https://github.com/FindYGL/-kingcobra_car |
