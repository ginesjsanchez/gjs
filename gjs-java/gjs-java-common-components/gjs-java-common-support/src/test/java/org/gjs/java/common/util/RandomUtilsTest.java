package org.gjs.java.common.util;

import static org.junit.jupiter.api.Assertions.assertTrue;

import org.gjs.java.common.util.RandomUtils;
import org.gjs.java.common.util.ValidationUtils;
import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

class RandomUtilsTest extends BaseClassTest<RandomUtils> {

    @Test
    void testGeneratePassword() {
        for (int i = 0; i < 100; i = i + 1) {
            final String passwd = RandomUtils.generatePassword();
            assertTrue(ValidationUtils.isValidPassword(passwd), String.format("Invalid password: %s", passwd));
        }
    }

}
