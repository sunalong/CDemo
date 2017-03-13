/**
 * Created by along on 17/3/13 14:48.
 * Email:466210864@qq.com
 * java中：
 * protected 修饰的成员变量和函数能被类本身、子类及同一个包中的类访问。
 */
public class ExternTest extends Father {
    public static void main(String[] args) {
        Father father = new Father();
        father.callInClass();
        father.proMethod();
        System.out.println();

        ProSon proSon = new ProSon();
        proSon.callInClass();
        proSon.proMethod();
    }

}

class Father {
    public Father() {
        priChar = "F priChar";
        protChar = "F proChar";
        pubChar = "F pubChar";
        System.out.println("Father 构造方法");
    }

    private String priChar;
    protected String protChar;

    protected void proMethod() {
        System.out.println("父类的 protected 方法");
    }

    public String pubChar;


    public void callInClass() {
        System.out.println("父类的公有方法");
    }
}

class ProSon extends Father {
    public ProSon() {
//        priChar = "F priChar";
        protChar = "S proChar";
        pubChar = "S pubChar";
        System.out.println("ProSon 构造方法");
    }
}