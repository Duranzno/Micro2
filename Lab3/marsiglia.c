 ADCValues[1]=ADCValues[1]/1023;
        ADCValues[1]=ADCValues[1]*3.56;
        
        i1 = ADCValues[1]/10;
        i2 = ADCValues[1]-(10*i1);
        bytetostr(i2, test);
        glcd_write_text(ltrim(test), 5+64, 1, 1);
        glcd_write_text(".", 11+64, 1, 1);
        n0 = (ADCValues[1] - 10*i1 - i2)*10000;
        d1 = n0/1000;
        bytetostr(d1, test);
        glcd_write_text(ltrim(test), 17+64, 1, 1);
        d2 = (n0 - d1*1000)/100;
        bytetostr(d2, test);
        glcd_write_text(ltrim(test), 23+64, 1, 1);
        d3 = (n0 - d1*1000 - d2*100)/10;
        bytetostr(d3, test);
        glcd_write_text(ltrim(test), 29+64, 1, 1);