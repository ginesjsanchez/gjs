package org.gjs.java.common.util;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.common.util.JpaUtils;
import org.gjs.java.test.BaseUnitTest;
import org.gjs.java.test.sample.model.SampleEntity;
import org.gjs.java.test.sample.model.SampleEntityWhitoutId;
import org.gjs.java.test.sample.model.SampleEntityWhitoutIdAnnotation;
import org.gjs.java.test.samples.pojos.SamplePojo;
import org.gjs.java.test.samples.type.MixedType;
import org.junit.jupiter.api.Test;

class JpaUtilsTest extends BaseUnitTest<JpaUtils> {

	@Test
	void testIsEntity() {
		try {
			assertFalse(JpaUtils.isEntity(SamplePojo.class));
			assertTrue(JpaUtils.isEntity(SampleEntity.class));
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Recibida excepcion");
		}
	}

	@Test
	void testGetIdAttribute() {
		try {
			String attribute = JpaUtils.getIdAttribute(SamplePojo.class);
			assertNotNull(attribute);
			assertEquals("id", attribute);
			attribute = JpaUtils.getIdAttribute(MixedType.class);
			assertNull(attribute);
			attribute = JpaUtils.getIdAttribute(SampleEntity.class);
			assertNotNull(attribute);
			assertEquals("id", attribute);
			attribute = JpaUtils.getIdAttribute(SampleEntityWhitoutIdAnnotation.class);
			assertNotNull(attribute);
			assertEquals("id", attribute);
			attribute = JpaUtils.getIdAttribute(SampleEntityWhitoutId.class);
			assertNull(attribute);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Recibida excepcion");
		}
	}

}
