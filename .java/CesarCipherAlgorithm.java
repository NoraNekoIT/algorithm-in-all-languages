public class CesarCipherAlgorithm {
    public static void main(String[] args) {
        String text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int s = 4;
        System.out.println("Text : " + text);
        System.out.println("Shift : " + s);
        System.out.println("Cipher: " + encrypt(text, s));
    }

    public static final String encrypt(final String source, final int offset) {
        return source.chars().map(c -> c + offset).mapToObj(c -> String.valueOf((char) c)).collect(Collectors.joining());
    }

    public static final String decrypt(final String source, final int offset) {
        return source.chars().map(c -> c - offset).mapToObj(c -> String.valueOf((char) c)).collect(Collectors.joining());
    }
}