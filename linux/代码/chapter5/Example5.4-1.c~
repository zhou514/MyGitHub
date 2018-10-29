#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <sys/soundcard.h>
	int setvol(int lvol,int rvol)
	{
	int fd=open("/dev/mixer",O_RDWR);
	short vol =lvol<<8 | rvol;
	int err=ioctl(fd,MIXER_WRITE(SOUND_MIXER_VOLUME),&vol);
	close(fd);
		}
	int getvol(int *lvol,int *rvol)
	{
    int fd=open("/dev/mixer",O_RDWR);
    short vol;
    int err=ioctl(fd,MIXER_READ(SOUND_MIXER_VOLUME),&vol);
    *lvol=vol >>8;
    *rvol=vol & 0xFF;
    close(fd);
     		}
	int main(int argc,char **argv)
		{
    	setvol(atoi(argv[1]),atoi(argv[2]));
     		}
     
