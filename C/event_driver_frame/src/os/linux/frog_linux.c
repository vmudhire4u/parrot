#include "frog_platform.h"
#include <signal.h>
#include <sys/time.h>

static void signal_handler(int sig)
{
	exit(0);

	return;
}

static void signal_int_handler(int sig)
{
	exit(0);

	return;
}


static void ftk_install_crash_signal(void)
{
	signal(SIGABRT, signal_handler);
	signal(SIGSEGV, signal_handler);
	signal(SIGILL,  signal_handler);
	signal(SIGINT,  signal_int_handler);

	return ;
}

static int ftk_set_tty_mode(int graphics)
{
	int r = 0;
	/*
#if !defined(PC_EMU) && defined(USE_LINUX_NATIVE)
	int fd = 0;
	fd = open("/dev/tty0", O_RDWR | O_SYNC);
	if (fd < 0)
		return -1;
	r = ioctl(fd, KDSETMODE, (void*) (graphics ? KD_GRAPHICS : KD_TEXT));
	close(fd);
#endif */
	return r;
}

size_t ftk_get_relative_time(void)
{
	struct timeval now = {0};
	gettimeofday(&now, NULL);

	return now.tv_sec*1000 + now.tv_usec/1000;
}

int ftk_platform_init(int argc, char** argv)
{
	ftk_set_tty_mode(1);
	ftk_install_crash_signal();

	return RET_OK;
}

void ftk_platform_deinit(void)
{
	ftk_set_tty_mode(0);

	return;
}

