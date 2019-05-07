package kernel.plugins.alipay;

import android.util.Base64;

import java.net.URLEncoder;
import java.security.KeyFactory;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.Signature;
import java.security.spec.PKCS8EncodedKeySpec;
import java.security.spec.X509EncodedKeySpec;

public class RSA {
    private static final String ALGORITHM = "RSA";
    private static final String PROVIDER = "BC";
    private static final String SIGN_ALGORITHMS = "SHA1WithRSA";
    private static final String INPUT_CHARSET = "utf-8";

    public static String sign(String content, String privateKey) {
        try {
            PKCS8EncodedKeySpec priPKCS8 = new PKCS8EncodedKeySpec(decode(privateKey));
            KeyFactory keyf = KeyFactory.getInstance(ALGORITHM, PROVIDER);
            PrivateKey priKey = keyf.generatePrivate(priPKCS8);

            Signature signature = Signature.getInstance(SIGN_ALGORITHMS);

            signature.initSign(priKey);
            signature.update(content.getBytes(INPUT_CHARSET));

            return URLEncoder.encode(encode(signature.sign()), INPUT_CHARSET);
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    public static boolean verify(String content, String sign, String publicKey) {
        try {
            X509EncodedKeySpec pubX509 = new X509EncodedKeySpec(decode(publicKey));
            KeyFactory keyf = KeyFactory.getInstance(ALGORITHM, PROVIDER);
            PublicKey pubKey = keyf.generatePublic(pubX509);

            Signature signature = Signature.getInstance(SIGN_ALGORITHMS);

            signature.initVerify(pubKey);
            signature.update(content.getBytes(INPUT_CHARSET));

            return signature.verify(decode(sign));
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    private static byte[] decode(String value) {
        return Base64.decode(value, Base64.DEFAULT);
    }

    private static String encode(byte[] value) {
        return new String(Base64.encode(value, Base64.DEFAULT));
    }
}
