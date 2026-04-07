package org.gjs.java.test.annotation;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.condition.EnabledIfEnvironmentVariable;
import org.junit.jupiter.api.condition.EnabledIfSystemProperty;
import org.springframework.core.annotation.AliasFor;

@Test
@EnabledIfEnvironmentVariable(matches = "", named = "")
public @interface GjsEnvironmentVarValueTest {

	@AliasFor(annotation = EnabledIfSystemProperty.class, attribute = "named")
	String named();

	@AliasFor(annotation = EnabledIfSystemProperty.class, attribute = "matches")
	String matches();

}
