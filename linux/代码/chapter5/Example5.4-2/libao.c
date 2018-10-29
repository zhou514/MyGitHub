#include <stdlib.h>
#include "libao.h"
//extern ao_t ao_alsa;
extern ao_t ao_dsp;
ao_t *ao_ls[]={
	//&ao_alsa,
	&ao_dsp,
	NULL
};

ao_t *getdev(ao_type_t type){
	int i=0;
	while(1){
		if (ao_ls[i]->info->type ==type) return ao_ls[i];
		else if (ao_ls[i]==NULL) return NULL;
		i++;
	}
}
