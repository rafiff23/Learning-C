#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data1
{
	int num;
	char name[255];
};

int main()
{
	//declarations

    int tc, N, num[255]={0}, cons;
    char temp[255]={0};
    struct data1 data[255]={0};

    scanf("%d", &tc); getchar();

    for(int i=0 ; i<tc ; i++)
	{
		scanf("%d", &N); getchar();

		for(int j=0 ; j<N ; j++)
		{
			scanf("%[^#]#%d", data[j].name, &data[j].num); getchar();

		}

		printf("Case #%d:\n", i+1);
		for(int j=0 ; j<N-1 ; j++)
		{
			for(int k=j+1 ; k<N ; k++)
			{
				if(data[j].num<data[k].num )
				{
					cons=data[j].num;
					data[j].num=data[k].num;
					data[k].num=cons;

					strcpy(temp, data[j].name);
					strcpy(data[j].name, data[k].name);
					strcpy(data[k].name, temp);

				}
			}
		}

		for(int j=0 ; j<N-1 ; j++)
		{
			for(int k=j+1 ; k<N ; k++)
			{
				if(strcmp(data[j].name, data[k].name)>0 && data[j].num == data[k].num)
				{
					strcpy(temp, data[j].name);
					strcpy(data[j].name, data[k].name);
					strcpy(data[k].name, temp);

					cons=data[j].num;
					data[j].num=data[k].num;
					data[k].num=cons;
				}
			}
		}

		for(int j=0 ; j<N ; j++)
		{
			printf("%s - %d\n", data[j].name, data[j].num);
			cons=0;
		}
	}
    return 0;
}
