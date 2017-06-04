package io.github.lizhangqu.uv;

import android.support.annotation.Keep;

/**
 * @version V1.0
 * @author: lizhangqu
 * @date: 2017-05-13 19:23
 */
@Keep
public class UV {
    static {
        System.loadLibrary("uv-jni");
    }

    public static native void test();
}
