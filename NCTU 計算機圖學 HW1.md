# NCTU 計算機圖學 HW1
## Programming environment
OS  : Windows 10
IDE : Visual Studio 2019

## Homework Part
### 1. Render a 3D cube with texture and let it rotate over time
以 $0,0,0$ 為原點，算出 8 個頂點的 $x,y,z$ 座標
分別畫出 Cube 的 6 個面
每個面的 4 個點都給 $x,y,z$ 座標、 texture 座標和面 normal
```
    // front
    glNormal3f(0, 0, 1);
    glTexCoord2f(0.0f, 0.0f);   glVertex3f(-0.5f, -0.5f, 0.5f); // bottom  left
    glTexCoord2f(1.0f, 0.0f);   glVertex3f(0.5f, -0.5f, 0.5f);// bottom right
    glTexCoord2f(1.0f, 1.0f);   glVertex3f(0.5f, 0.5f, 0.5f);// top right
    glTexCoord2f(0.0f, 1.0f);   glVertex3f(-0.5f, 0.5f, 0.5f);// top left
```
使用 glfwGetTime() 讓 Cube 隨著時間旋轉
```
    glRotatef((float)glfwGetTime()* 45.0f, 1, 1, 0)
``` 
### 2. Render two spheres with two textures and let them rotate over time
![](https://i.imgur.com/rTnP3GD.png)

$x=r*cos\phi*cos\theta$
$y=r*cos\phi*sin\theta$
$x=r*sin\phi$

$\theta=2*\pi*\dfrac{j}{slice}$
$\phi=\dfrac{\pi}{2}-\pi*\dfrac{i}{stack}$

以$\theta = 0$、$\phi = 90$ 為四邊形的左上角
往右往下依序計算每個點的
 - $x、y、z$ 座標
 - texture 座標
 - normal
 
![](https://i.imgur.com/jEEwOZm.png)

接著從左上開始計算每個四邊形的 4 個點是由哪 4 個點組成
將 4 個點的 index 以 $k1, k1+1, k2, k2+1$ 的順序儲存

接著根據四邊形的點 index 用 GL_QUADS 畫出全部四邊形


### 3. Add lighting component to the scene
在畫 Cube 和 Sphere 的時候，計算 normal 
依照作業要求設定光源
```
GLfloat position[] = { 10, 10, 10 };
GLfloat ambient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };

glLightfv(GL_LIGHT0, GL_POSITION, position);
glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
```
啟用光源 
```
glEnable(GL_LIGHT0);
glEnable(GL_LIGHTING);
```
### 4. Some keyboard callback functions for switching three objects
在 key_callback 裡使用 switch (key) 來改變顯示的 object

| case       | object   |
| --------   | -------- | 
| GLFW_KEY_1 | EARTH    |
| GLFW_KEY_2 | MOON     | 
| GLFW_KEY_3 | CUBE     | 

    
### 5. Use keyboard or mouse event to change camera view
用 camera_x,y,z 決定 camera 位置
```
double camera_x = 0;
double camera_y = 0;
double camera_z = 5;
gluLookAt(camera_x,camera_y,camera_z, camera_x,camera_y,-1, 0,1,0);
```
#### 使用鍵盤操控 camera 的 x 和 y
在 key_callback 裡使用 switch (key) 來移動
    
| case       | 操作        | 結果 |
| --------   | ---------  | -------|
| GLFW_KEY_W | camera_y + | 視角向上 |
| GLFW_KEY_A | camera_x - | 視角向左 |
| GLFW_KEY_S | camera_y - | 視角向下 |
| GLFW_KEY_D | camera_x + | 視角向右 |
    
#### 使用滑鼠滾輪操控 camera 的 z
在 scroll_callback 裡根據 yoffset 改變視角遠近

| case     | 結果 |
| -------- | ------- |
| 滾輪向上 (yoffset增加) |視角拉近 |
| 滾輪向下 (yoffset減少) |視角拉遠 |

        
#### 使用滑鼠操控 camera 的 x 和 y
 - 左鍵按住改變 camera 視角
 - 右鍵 camera 視角變回預設位置

設置一個變數 cameraMove 
當 cameraMove 為 1 ， 每次更新都依據滑鼠的座標改變值來移動 camera 
當 cameraMove 為 0 ， 不做任何動作

在 mouse_button_callback() 設定

| case | 結果 | 
| -------- | -------- |
| GLFW_MOUSE_BUTTON_LEFT && GLFW_PRESS     | cameraMove 設為 1  |
| GLFW_MOUSE_BUTTON_LEFT && GLFW_RELEASE   | cameraMove 設為 0  | 
| GLFW_MOUSE_BUTTON_RIGHT && GLFW_PRESS    | camera_x,y,z 設為預設值   |


## Problems
Problem2 的 Sphere 原本每個四邊形都是用 2 個 GL_TRAINGLES 來畫
但是這樣畫面跑起來很卡 
改成 GL_QUADS 來畫之後，就順很多了
