import java.io.FileInputStream;
import java.nio.charset.StandardCharsets;
import java.util.*;
import java.io.*;


public class Main {
    public static void main(String[] args) throws IOException {
        System.out.println("Hello World");
        // 这种方法就可以调用自动关闭
        try (InputStream input = new FileInputStream("resources/test.txt")) {
            byte[] buffer = new byte[1024];
            int n;
            
            while ((n = input.read(buffer)) != -1) {
                String s = new String(buffer, StandardCharsets.UTF_8);
                System.out.println("read " + n + " bytes."); // 字节等于(1位一个字节加上换行符号)
                System.out.println(s);
            }

        }
    }
}