package org.gjs.java.test.annotation;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.condition.DisabledOnOs;
import org.junit.jupiter.api.condition.OS;

@Test
@DisabledOnOs({ OS.AIX, OS.FREEBSD, OS.LINUX, OS.OPENBSD, OS.SOLARIS })
public @interface GjsUnixTest {

}
