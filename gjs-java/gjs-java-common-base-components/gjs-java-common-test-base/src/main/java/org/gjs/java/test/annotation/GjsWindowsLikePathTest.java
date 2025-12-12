package org.gjs.java.test.annotation;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.condition.EnabledIfSystemProperty;

@Test
@EnabledIfSystemProperty(named = "file.separator", matches = "[\\]")
public @interface GjsWindowsLikePathTest {

}
