#include <signal.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define KEYCODE_R 0x43
#define KEYCODE_L 0x44
#define KEYCODE_U 0x41
#define KEYCODE_D 0x42
#define KEYCODE_Q 0x71

int kfd = 0;
struct termios cooked, raw;

void quit(int sig)
{
  (void)sig;
  tcsetattr(kfd, TCSANOW, &cooked);//在程序结束时在恢复原来的配置
  exit(0);
}

void keyLoop()
{
  char c;

  // get the console in raw mode
  tcgetattr(kfd, &cooked); // 得到 termios 结构体保存，然后重新配置终端
  memcpy(&raw, &cooked, sizeof(struct termios));
  raw.c_lflag &=~ (ICANON | ECHO);
  // Setting a new line, then end of file
  raw.c_cc[VEOL] = 1;
  raw.c_cc[VEOF] = 2;
  tcsetattr(kfd, TCSANOW, &raw);

  puts("Reading from keyboard");
  puts("---------------------------");
  puts("Use arrow keys to move the robot.");
  puts("otherwise the key values will be printed");


  for(;;)
  {
    // get the next event from the keyboard
    if(read(kfd, &c, 1) < 0)
    {
      perror("read():");
      exit(-1);
    }

    switch(c)
    {
      case KEYCODE_L:
        printf("LEFT\n");
        break;
      case KEYCODE_R:
        printf("RIGHT\n");
        break;
      case KEYCODE_U:
        printf("UP\n");
        break;
      case KEYCODE_D:
        printf("DOWN\n");
        break;
          default:
                printf("value: %c = 0x%02X = %d\n", c, c, c);
    }
  }
  return;
}


int main(int argc, char** argv)
{
  // signal(SIGINT,quit);

  keyLoop();

  return(0);
}
