<template>
  <div class="game-container">
    <div class="score">得分: {{ score }}</div>
    <div
      class="game-board"
      :style="{
        width: boardSize + 'px',
        height: boardSize + 'px'
      }"
    >
      <div
        v-for="segment in snake"
        :key="`${segment.x}-${segment.y}`"
        class="snake-segment"
        :class="{ 'snake-head': segment === snake[0] }"
        :style="{
          width: cellSize + 'px',
          height: cellSize + 'px',
          left: segment.x * cellSize + 'px',
          top: segment.y * cellSize + 'px',
          backgroundImage: segment === snake[0] ? 'url(' + cxkHead + ')' : 'none'
        }"
      ></div>
      <div
        class="food"
        :style="{
          width: cellSize + 'px',
          height: cellSize + 'px',
          left: food.x * cellSize + 'px',
          top: food.y * cellSize + 'px'
        }"
      ></div>
      <div v-if="gameOver" class="game-over">
        <h2>游戏结束</h2>
        <p>最终得分: {{ score }}</p>
        <button class="restart-button" @click="restartGame">重新开始</button>
      </div>
    </div>
  </div>
</template>

<script>
import { ref, onMounted, onUnmounted } from 'vue'
import cxkHead from './assets/cxk.svg'

export default {
  name: 'App',
  setup() {
    const cellSize = 20
    const gridSize = 20
    const boardSize = cellSize * gridSize
    const snake = ref([
      { x: 10, y: 10 },
      { x: 9, y: 10 },
      { x: 8, y: 10 }
    ])
    const direction = ref('right')
    const food = ref(generateFood())
    const score = ref(0)
    const gameOver = ref(false)
    let gameLoop = null

    function generateFood() {
      const newFood = {
        x: Math.floor(Math.random() * gridSize),
        y: Math.floor(Math.random() * gridSize)
      }
      
      // 确保食物不会生成在蛇身上
      if (snake.value.some(segment => segment.x === newFood.x && segment.y === newFood.y)) {
        return generateFood()
      }
      return newFood
    }

    function moveSnake() {
      if (gameOver.value) return

      const head = { ...snake.value[0] }
      switch (direction.value) {
        case 'up':
          head.y--
          break
        case 'down':
          head.y++
          break
        case 'left':
          head.x--
          break
        case 'right':
          head.x++
          break
      }

      // 检查是否撞墙
      if (
        head.x < 0 ||
        head.x >= gridSize ||
        head.y < 0 ||
        head.y >= gridSize
      ) {
        gameOver.value = true
        return
      }

      // 检查是否撞到自己
      if (snake.value.some(segment => segment.x === head.x && segment.y === head.y)) {
        gameOver.value = true
        return
      }

      snake.value.unshift(head)

      // 检查是否吃到食物
      if (head.x === food.value.x && head.y === food.value.y) {
        score.value += 10
        food.value = generateFood()
      } else {
        snake.value.pop()
      }
    }

    function handleKeyPress(event) {
      const key = event.key.toLowerCase()
      switch (key) {
        case 'w':
          if (direction.value !== 'down') direction.value = 'up'
          break
        case 's':
          if (direction.value !== 'up') direction.value = 'down'
          break
        case 'a':
          if (direction.value !== 'right') direction.value = 'left'
          break
        case 'd':
          if (direction.value !== 'left') direction.value = 'right'
          break
      }
    }

    function startGame() {
      gameLoop = setInterval(moveSnake, 150)
    }

    function restartGame() {
      snake.value = [
        { x: 10, y: 10 },
        { x: 9, y: 10 },
        { x: 8, y: 10 }
      ]
      direction.value = 'right'
      score.value = 0
      food.value = generateFood()
      gameOver.value = false
      if (gameLoop) clearInterval(gameLoop)
      startGame()
    }

    onMounted(() => {
      window.addEventListener('keydown', handleKeyPress)
      startGame()
    })

    onUnmounted(() => {
      window.removeEventListener('keydown', handleKeyPress)
      if (gameLoop) clearInterval(gameLoop)
    })

    return {
      snake,
      food,
      score,
      gameOver,
      cellSize,
      boardSize,
      cxkHead,
      restartGame
    }
  }
}
</script>