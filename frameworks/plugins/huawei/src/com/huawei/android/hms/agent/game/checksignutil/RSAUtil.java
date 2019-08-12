/*
Copyright (C) Huawei Technologies Co., Ltd. 2015. All rights reserved.
See LICENSE.txt for this sample's licensing information.
*/

package com.huawei.android.hms.agent.game.checksignutil;

import android.text.TextUtils;

import com.huawei.android.hms.agent.common.HMSAgentLog;

import java.io.UnsupportedEncodingException;
import java.net.URLDecoder;
import java.net.URLEncoder;
import java.security.KeyFactory;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.Signature;
import java.security.spec.PKCS8EncodedKeySpec;
import java.security.spec.X509EncodedKeySpec;

public class RSAUtil {

	public static final String KEY_ALGORITHM = "RSA";

	public static final String SIGNATURE_ALGORITHM_SHA256 = "SHA256WithRSA";

	public static boolean doCheck(String content, String sign, String publicKey) {
		if (TextUtils.isEmpty(publicKey)) {
			return false;
		}
		try {
			KeyFactory keyFactory = KeyFactory.getInstance(KEY_ALGORITHM);
			byte[] encodedKey = Base64Util.decode(publicKey);
			PublicKey pubKey = keyFactory.generatePublic(new X509EncodedKeySpec(encodedKey));

            Signature signature = Signature.getInstance(SIGNATURE_ALGORITHM_SHA256);
            
            signature.initVerify(pubKey);
            signature.update(content.getBytes("utf-8"));
            
            return signature.verify(Base64Util.decode(sign));
        }
        catch (Exception localException) {
			HMSAgentLog.e("check error");
        }
        return false;
    }

	public static String sign(String content, String privateKey) {
		if ((content == null) || (privateKey == null)) {
			return null;
		}
		String charset = "utf-8";
		try {
			PKCS8EncodedKeySpec priPKCS8 = new PKCS8EncodedKeySpec(Base64Util.decode(privateKey));
			KeyFactory keyf = KeyFactory.getInstance(KEY_ALGORITHM);
			PrivateKey priKey = keyf.generatePrivate(priPKCS8);

            Signature signature = Signature.getInstance(SIGNATURE_ALGORITHM_SHA256);
            
            signature.initSign(priKey);
            signature.update(content.getBytes(charset));
            
            byte[] signed = signature.sign();
            
            return Base64Util.encode(signed);
        }
        catch (Exception localException) {
			HMSAgentLog.e("sign error");
        }
        return null;
    }



	public static String urlEncode(String src) {
		if(src == null) {
			return null;
		}else {
			try {
				return URLEncoder.encode(src, "UTF-8").replace("+", "%20").replace("*", "%2A").replace("~", "%7E");
			} catch (UnsupportedEncodingException var2) {
				return null;
			}
		}
	}

	public static String urlDecode(String src)
	{
		if(src == null) {
			return null;
		}else {
			try {
				return URLDecoder.decode(src, "UTF-8");
			} catch (UnsupportedEncodingException var2) {
				return null;
			}
		}
	}
}
