import java.util.*;

public class Main {
    public static void main(String args[]) {
        // 通过匿名继承的方式(new TestClass() {} 这种方法就是匿名继承)进行调用(不同包的)保护成员函数，因为子类能够使用父类的protected方法
        new TestClass() {
            @Override
            protected void printTest() {
                super.printTest();
            }
        }.printTest();
    }
}

// 假设在不同的包中
class TestClass {
    // 保护成员函数
    protected void printTest() {
        System.out.println("in print test...");
    }
}