package org.gjs.java.test.annotation;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.condition.EnabledOnOs;
import org.junit.jupiter.api.condition.OS;

@Test
@EnabledOnOs({ OS.AIX, OS.FREEBSD, OS.LINUX, OS.OPENBSD, OS.SOLARIS })
public @interface GjsNotUnixTest {

}
