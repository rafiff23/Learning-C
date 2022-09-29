#include <stdio.h>

// function to return Alphabet according to given number
char getAlphabet(char number){
        if(number =='0'){ return 'O'; }
        else if(number =='1'){ return 'I'; }
        else if(number =='3'){ return 'E'; }
        else if(number =='4'){ return 'A'; }
        else if(number =='5'){ return 'S'; }
        else if(number =='6'){ return 'G'; }
        else if(number =='7'){ return 'T'; }
        else if(number =='8'){ return 'B'; }
        // return given char if above conditions are false
        return number;
}

int main(){
        // open file in read mode
        FILE *file;
        file = fopen("testdata.in","r");

        // variable to store no.of.test cases,shift count
        int t=0,shift;

        // char array to store upto 1000 characters
        char line[1000];
        // variables for iterations
        int i,j;

        // if file is opened
        if(file != NULL){
                // read testcases count from file
                fscanf(file," %d",&t);

                // loop for test case times
                for(i=0; i<t ;i++){
                        // read shift number from file
                        fscanf(file," %d",&shift);
                        // skip newline
                        fgetc(file);
                        // read encrypted line until end of line from file
                        fscanf(file,"%[^\n]",line);

                        // index starting from 0
                        j=0;
                        //loop until character at index j is not null
                        while(line[j] != '\0'){
                                // get alphabet using function
                                line[j] = getAlphabet(line[j]);

                                // if character is not space
                                if(line[j] != ' '){
                                        // shifft character
                                        line[j] = line[j] - shift;

                                        // if character below ascii of 'A'
                                        if(line[j] < 65){
                                                // udpate ascii from 'Z'
                                                line[j] = 90 - (65-line[j]-1);
                                        }
                                        // if character above ascii of 'Z'
                                        else if(line[j] > 90){
                                                // udpate ascii from 'A'
                                                line[j] = 65 + (line[j]-90-1);
                                        }
                                }
                                // increase index by 1
                                j++;
                        }
                        // print line number and line
                        printf("Case #%d: %s\n",(i+1),line);
                        
                }
        }

        // close file
        fclose(file);
        return 0;
}
