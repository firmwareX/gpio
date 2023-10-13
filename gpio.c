#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const char *get_path(char *pin){
  char *path=(char*)malloc(50);
  strcpy(path,"/sys/class/gpio/gpio");
  strcat(path,pin);
  strcat(path,"/");
  return path;
}

const void unset(char *pin){
  FILE *un = fopen("/sys/class/gpio/unexport","w");
  fputs(pin,un);
  fclose(un);
}

void setup(char *pin,char *dir){
  FILE *fp = fopen("/sys/class/gpio/export","w+");
  fputs(pin,fp);
  fclose(fp);
  char path_direction[50];
  strcpy(path_direction,get_path(pin));
  strcat(path_direction,"direction");
  int i;
  for(i=0;i<100000000;i++){;}
  FILE *d = fopen(path_direction,"w+");
  fputs(dir,d);
  fclose(d);
}

const void read(char *pin){
  char path_value[50];
  strcpy(path_value,get_path(pin));
  strcat(path_value,"value");
  FILE *v = fopen(path_value,"r");
  char val[2];
  fgets(val,2,v);
  fclose(v);
  printf("%s",val);
}

const void write(char *pin,char *value){
  char path_value[50];
  strcpy(path_value,get_path(pin));
  strcat(path_value,"value");
  FILE *v = fopen(path_value,"w+");
  fputs(value,v);
  fclose(v);
}

int main(int argc,char *argv[]){
  if(strcmp(argv[1],"set") == 0){
    setup(argv[2],argv[3]);
  }
  if(strcmp(argv[1],"write") == 0){
    write(argv[2],argv[3]);
  }
  if(strcmp(argv[1],"read") == 0){
    read(argv[2]);
  }
  if(strcmp(argv[1],"unset") == 0){
    unset(argv[2]);
  }
  return EXIT_SUCCESS;
}
