package org.gjs.java.test.annotation;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.condition.EnabledIfSystemProperty;
import org.springframework.core.annotation.AliasFor;

@Test
@EnabledIfSystemProperty(matches = "", named = "")
public @interface GjsPropertyValueTest {

	@AliasFor(annotation = EnabledIfSystemProperty.class, attribute = "named")
	String named();

	@AliasFor(annotation = EnabledIfSystemProperty.class, attribute = "matches")
	String matches();

}
