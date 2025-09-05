# Snake Game with Vue 3

一个基于Vue 3开发的贪吃蛇游戏，使用蔡徐坤头像作为蛇头。

## 项目特色

- 🎮 经典贪吃蛇游戏玩法
- 🎯 Vue 3 Composition API
- 🎨 蔡徐坤头像蛇头设计
- 📱 响应式界面设计
- ⚡ 使用Vite构建工具

## 技术栈

- **Vue 3** - 前端框架
- **Vite** - 构建工具
- **CSS3** - 样式设计

## 项目结构

```
snake-game/
├── src/
│   ├── App.vue          # 主组件
│   ├── main.js          # 入口文件
│   └── assets/
│       ├── main.css     # 样式文件
│       └── cxk.svg      # 蔡徐坤头像
├── index.html           # HTML模板
├── package.json         # 项目配置
├── vite.config.js       # Vite配置
└── README.md           # 项目说明
```

## 安装和运行

1. 安装依赖：
```bash
npm install
```

2. 启动开发服务器：
```bash
npm run dev
```

3. 构建生产版本：
```bash
npm run build
```

4. 预览生产版本：
```bash
npm run preview
```

## 游戏玩法

- 使用 **WASD** 键控制蛇的移动方向
- **W** - 向上移动
- **A** - 向左移动
- **S** - 向下移动
- **D** - 向右移动
- 吃到食物得分增加10分
- 撞墙或撞到自己游戏结束

## 游戏特性

- 20x20的游戏网格
- 实时分数显示
- 游戏结束提示
- 一键重新开始
- 蛇头使用蔡徐坤头像

## 开发说明

这个项目是使用Vue 3的Composition API开发的，展示了以下特性：

- `ref` 和响应式数据管理
- 生命周期钩子 (`onMounted`, `onUnmounted`)
- 事件监听和清理
- 定时器管理
- 条件渲染和列表渲染

## 浏览器支持

支持所有现代浏览器，包括：
- Chrome (推荐)
- Firefox
- Safari
- Edge

## 许可证

MIT License

## 贡献

欢迎提交Issue和Pull Request来改进这个项目！