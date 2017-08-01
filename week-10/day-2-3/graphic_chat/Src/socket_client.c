/* Includes ------------------------------------------------------------------*/
#include "socket_client.h"
#include "socket_server.h"
#include "lcd_log.h"
#include "cmsis_os.h"
#include "app_ethernet.h"
#include "lwip/sockets.h"
#include "stm32746g_discovery_ts.h"
#include <string.h>

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

#define SERVER_IP           "10.27.6.118" //"10.27.6.113"
#define SERVER_PORT         54545
#define DATA_BUFFER_SIZE    64

#define XMAX 480
#define YMAX 272



/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

TS_StateTypeDef ts_state;
TS_StateTypeDef *ts_state_ptr = &ts_state;
TS_StateTypeDef ts_state_prev;
TS_StateTypeDef *ts_state_prev_ptr = &ts_state_prev;

uint16_t radius;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

typedef struct {
	int32_t x;
	int32_t y;
} coordinate_t;



void touch_detect_thread()
{
	BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());

	radius = 10;

	BSP_TS_GetState(ts_state_ptr);
			if (ts_state.touchDetected) {
				if (ts_state_ptr->touchX[0] < 420 - radius	&&
					ts_state_ptr->touchX[0] > radius		&&
					ts_state_ptr->touchY[0] < 272 - radius	&&
					ts_state_ptr->touchY[0] > radius) {
					BSP_LCD_SelectLayer(0);
					BSP_LCD_FillCircle(ts_state_ptr->touchX[0], ts_state_ptr->touchY[0], radius);
				}

			}

}








int send_message(int socket)
	{
		// Get the message from the user
		char msg[DATA_BUFFER_SIZE];
		LCD_ErrLog("\nEnter the message to send: ");
		gets(msg);
		// Send the message to the servers
		int sent_bytes = send(socket, msg, strlen(msg), 0);
		if (sent_bytes < 0)
			LCD_ErrLog("send() ");

		return sent_bytes;
	}

// TODO:
// Implement this function!
void socket_client_thread(void const *argument)
{
	int client_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_IP);

	struct sockaddr_in addr_in;
		addr_in.sin_family = AF_INET;
		addr_in.sin_port = htons(SERVER_PORT);
		addr_in.sin_addr.s_addr = inet_addr(SERVER_IP);

	connect(client_sock, (struct sockaddr *)&addr_in, sizeof(addr_in));


	int client_socket = 0;
	int sent_bytes;
		int received_bytes;
		char recv_buff[DATA_BUFFER_SIZE];
		do {
			// Send data to the server
			sent_bytes = send_message(client_socket);
			// Receive the answer if message was sent
			if (sent_bytes > 0) {
				received_bytes = recv(client_socket, recv_buff, DATA_BUFFER_SIZE, 0);
				// Error handling
				if (received_bytes < 0) {
					LCD_ErrLog("recv() ");
				} else {
					// Printing out received string
					recv_buff[received_bytes] = '\0';
					LCD_ErrLog("Received string: %s\n", recv_buff);
				}
			}
		} while (sent_bytes > 0);

		LCD_ErrLog("Closing the socket...\n");
		closesocket(client_socket);
		LCD_ErrLog("Cleaning up memory...\n");


}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
