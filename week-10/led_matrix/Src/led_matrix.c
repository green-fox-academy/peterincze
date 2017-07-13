/* Includes ------------------------------------------------------------------*/
#include "led_matrix.h"
#include "stm32f7xx_hal.h"
#include "lcd_log.h"
#include "cmsis_os.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

// Each LED state is stored in this 2D array
GPIO_PinState led_matrix_state[LED_MATRIX_ROWS][LED_MATRIX_COLS];

// Mutex definition
osMutexDef(LED_MATRIX_MUTEX_DEF);

// Mutex global variable
osMutexId led_matrix_mutex_id;

/* Private function prototypes -----------------------------------------------*/
void led_matrix_set(uint8_t row, uint8_t col, uint8_t state);
/* Private functions ---------------------------------------------------------*/

// TODO:
// Write this function!
void led_matrix_set(uint8_t row, uint8_t col, uint8_t state) {
	// TODO:
	// Wait for the mutex

	// TODO:
	// Change the LED in the selected row and col to the specified state
	// Use the led_matrix_state 2D array variable!
	led_matrix_state[row] [col] = state;

	// TODO:
	// Release the mutex
}

typedef struct{
	GPIO_TypeDef *GPIOx;
	uint16_t GPIO_Pin;
}column;

typedef struct{
	GPIO_TypeDef *GPIOx;
	uint16_t GPIO_Pin;
}row;

void pin_init()			//pinek bealitasa
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_GPIOB_CLK_ENABLE();
		__HAL_RCC_GPIOC_CLK_ENABLE();
		__HAL_RCC_GPIOG_CLK_ENABLE();
		__HAL_RCC_GPIOH_CLK_ENABLE();
		__HAL_RCC_GPIOI_CLK_ENABLE();

		GPIO_InitTypeDef gpio_a;
		gpio_a.Pin = GPIO_PIN_15 | GPIO_PIN_8;
		gpio_a.Mode = GPIO_MODE_OUTPUT_PP;
		gpio_a.Pull = GPIO_NOPULL;
		gpio_a.Speed = GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOA, &gpio_a);

		GPIO_InitTypeDef gpio_b;
		gpio_b.Pin = GPIO_PIN_15 | GPIO_PIN_4;
		gpio_b.Mode = GPIO_MODE_OUTPUT_PP;
		gpio_b.Pull = GPIO_NOPULL;
		gpio_b.Speed = GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOB, &gpio_b);

		GPIO_InitTypeDef gpio_c;
		gpio_c.Pin = GPIO_PIN_7 | GPIO_PIN_6;
		gpio_c.Mode = GPIO_MODE_OUTPUT_PP;
		gpio_c.Pull = GPIO_NOPULL;
		gpio_c.Speed = GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOC,  &gpio_c);

		GPIO_InitTypeDef gpio_g;
		gpio_g.Pin = GPIO_PIN_6 | GPIO_PIN_7;
		gpio_g.Mode = GPIO_MODE_OUTPUT_PP;
		gpio_g.Pull = GPIO_NOPULL;
		gpio_g.Speed = GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOG,  &gpio_g);

		GPIO_InitTypeDef gpio_h;
		gpio_h.Pin = GPIO_PIN_6;
		gpio_h.Mode = GPIO_MODE_OUTPUT_PP;
		gpio_h.Pull = GPIO_NOPULL;
		gpio_h.Speed = GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOH, &gpio_h);

		GPIO_InitTypeDef gpio_i;
		gpio_i.Pin = GPIO_PIN_0 | GPIO_PIN_3 | GPIO_PIN_2;
		gpio_i.Mode = GPIO_MODE_OUTPUT_PP;
		gpio_i.Pull = GPIO_NOPULL;
		gpio_i.Speed = GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOI, &gpio_i);
}

// TODO:
// Write this function!
void led_matrix_update_thread(void const *argument)
{
	// TODO:
	// Initialize the pins as outputs and the led_matrix_state 2D array

	pin_init();

	column LED_column[LED_MATRIX_COLS] = {
		{GPIOC, GPIO_PIN_7},
		{GPIOC, GPIO_PIN_6},
		{GPIOG, GPIO_PIN_6},
		{GPIOB, GPIO_PIN_4},
		{GPIOG, GPIO_PIN_7}
	};

	row LED_row[LED_MATRIX_ROWS] = {
		{GPIOI, GPIO_PIN_0},
		{GPIOH, GPIO_PIN_6},
		{GPIOI, GPIO_PIN_3},
		{GPIOI, GPIO_PIN_2},
		{GPIOA, GPIO_PIN_15},
		{GPIOA, GPIO_PIN_8},
		{GPIOB, GPIO_PIN_15}
	};

	// TODO:
	// Create a mutex
	// Use the LED_MATRIX_MUTEX_DEF


	LCD_UsrLog("led_matrix - initialized\n");

	// Infinite loop
	while (1) {
		// TODO:
		// Implement the led matrix updater functionality

//		for (int i = 0; i < LED_MATRIX_COLS; i++) {
//			HAL_GPIO_WritePin(LED_column[i].GPIOx, LED_column[i].GPIO_Pin, GPIO_PIN_SET);
//		}
		for (int j = 0; j < LED_MATRIX_ROWS; j++) {
			HAL_GPIO_WritePin(LED_row[j].GPIOx, LED_row[j].GPIO_Pin, GPIO_PIN_SET);
		}

		for (int i = 0; i < LED_MATRIX_COLS; i++) {
			HAL_GPIO_WritePin(LED_column[i].GPIOx, LED_column[i].GPIO_Pin, GPIO_PIN_SET);
			for (int j = 0; j < LED_MATRIX_ROWS; j++) {
				if (i % 2 != 0) {
					HAL_GPIO_WritePin(LED_row[6 - j].GPIOx, LED_row[6 - j].GPIO_Pin, GPIO_PIN_RESET);
					osDelay(100);
					HAL_GPIO_WritePin(LED_row[6 - j].GPIOx, LED_row[6 - j].GPIO_Pin, GPIO_PIN_SET);
				}
				else {
				HAL_GPIO_WritePin(LED_row[j].GPIOx, LED_row[j].GPIO_Pin, GPIO_PIN_RESET);
				osDelay(100);
				HAL_GPIO_WritePin(LED_row[j].GPIOx, LED_row[j].GPIO_Pin, GPIO_PIN_SET);
				}
			}
			HAL_GPIO_WritePin(LED_column[i].GPIOx, LED_column[i].GPIO_Pin, GPIO_PIN_RESET);

		}
		for (int i = LED_MATRIX_ROWS-1; i >= 0; i--) {
				HAL_GPIO_WritePin(LED_row[i].GPIOx, LED_row[i].GPIO_Pin, GPIO_PIN_RESET);
				for (int j = LED_MATRIX_COLS-1; j >= 0; j--) {
					if (i % 2 == 0) {
						HAL_GPIO_WritePin(LED_column[j].GPIOx, LED_column[j].GPIO_Pin, GPIO_PIN_SET);
						osDelay(100);
						HAL_GPIO_WritePin(LED_column[j].GPIOx, LED_column[j].GPIO_Pin, GPIO_PIN_RESET);
					}
					else {
					HAL_GPIO_WritePin(LED_column[4 - j].GPIOx, LED_column[4 - j].GPIO_Pin, GPIO_PIN_SET);
					osDelay(100);
					HAL_GPIO_WritePin(LED_column[4 - j].GPIOx, LED_column[4 - j].GPIO_Pin, GPIO_PIN_RESET);
					}
				}
				HAL_GPIO_WritePin(LED_row[i].GPIOx, LED_row[i].GPIO_Pin, GPIO_PIN_SET);

				}

		// Step 1:
		// Iterate through every column or row

			// Step 2:
			// Wait for the mutex


			// Step 3:
			// Turn on the column or row


			// Step 4:
			// Turn on the leds in that column or row


			// Step 5:
			// Release the mutex


			// Step 6:
			// Delay


			// Step 7:
			// Turn off the column or row
	}

	// Terminating thread
	while (1) {
		LCD_ErrLog("led_matrix - terminating...\n");
		osThreadTerminate(NULL);
	}
}

// This thread is a waterfall type animation
void led_matrix_waterfall_thread(void const *argument)
{
	while (1) {
		for (uint8_t r = 0; r < LED_MATRIX_ROWS; r++) {
			for (uint8_t c = 0; c < LED_MATRIX_COLS; c++) {
				led_matrix_set(r, c, 1);
				osDelay(50);
				led_matrix_set(r, c, 0);
			}
		}
	}

	while (1) {
		LCD_ErrLog("led_matrix_waterfall - terminating...\n");
		osThreadTerminate(NULL);
	}
}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
