void space1(){
        while(!HID_Write(space,64));        
}
void space2(){
        while(!HID_Write(space,64));
        while(!HID_Write(space,64));
}
void write(char *txt){
        space2();
        while(!HID_Write(txt,64));
}
void menu2(){
        write(menu);
        write("--------------------------------------------------");
        write("CASO A ");
        write("CASO B ");
        write("CASO C ");
        space1();
        space1();
        space1();
        space1();
        space1();        
}