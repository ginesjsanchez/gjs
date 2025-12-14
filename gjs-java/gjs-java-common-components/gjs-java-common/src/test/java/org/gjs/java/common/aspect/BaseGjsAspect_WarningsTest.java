package org.gjs.java.common.aspect;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.fail;

import java.util.ArrayList;
import java.util.List;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.Signature;
import org.aspectj.lang.reflect.SourceLocation;
import org.gjs.java.common.aspect.BaseGjsAspect;
import org.gjs.java.common.dto.AuditDto;
import org.gjs.java.common.enums.AuditLogType;
import org.gjs.java.test.BaseUnitTest;
import org.gjs.java.test.samples.aspect.TargetAspectSample;
import org.junit.jupiter.api.Test;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.Mockito;

import lombok.Getter;

public class BaseGjsAspect_WarningsTest extends BaseUnitTest<BaseGjsAspect> {

	@Getter
	class TestGjsAspect extends BaseGjsAspect {

		private int warnings = 0;

		@Override
		protected long criticalTime() {
			return 100;
		}

		@Override
		protected void whenTimeWarn(AuditDto auditDto) {
			warnings = warnings + 1;
		}

		public void log(JoinPoint joinPoint) {
			getLogger(joinPoint).debug(super.formatLog(joinPoint));
		}

		public void logBefore(JoinPoint joinPoint) {
			getLogger(joinPoint).debug(super.formatLog(joinPoint, AuditLogType.BEGIN));
		}

		public void logAfter(JoinPoint joinPoint) {
			getLogger(joinPoint).debug(super.formatLog(joinPoint, AuditLogType.END));
		}

		public void logReturn(JoinPoint joinPoint, Object result) {
			getLogger(joinPoint).debug(super.formatLog(joinPoint, AuditLogType.RETURNS), result);
		}

		public void logThrow(JoinPoint joinPoint, Exception ex) {
			getLogger(joinPoint).debug(super.formatLog(joinPoint, AuditLogType.THROWS),
					ex.getClass().getCanonicalName(), ex.getMessage());
		}
	}

	@Mock
	private ProceedingJoinPoint proceedingJoinPoint;

	@Mock
	private Signature signature;

	@Mock
	private SourceLocation sourceLocation;

	@InjectMocks
	private TestGjsAspect GjsAspect;

	private static TargetAspectSample targetAspectSample;

	@Override
	protected void initialize() throws Exception {
		GjsAspect = new TestGjsAspect();
		targetAspectSample = new TargetAspectSample();
	}

	@Test
	public void testGjsAspect1() {
		try {
			final List<Object> listArgs = new ArrayList<>();
			final Object args[] = listArgs.toArray(new Object[listArgs.size()]);
			final String signatureName = "Run";
			Mockito.when(proceedingJoinPoint.getTarget()).thenReturn(targetAspectSample);
			Mockito.when(proceedingJoinPoint.getArgs()).thenReturn(args);
			Mockito.when(proceedingJoinPoint.getSignature()).thenReturn(signature);
			Mockito.when(signature.getName()).thenReturn(signatureName);

			assertEquals(0, GjsAspect.getWarnings());
			GjsAspect.logBefore(proceedingJoinPoint);
			Thread.sleep(50);
			GjsAspect.logAfter(proceedingJoinPoint);
			assertEquals(0, GjsAspect.getWarnings());
			GjsAspect.logBefore(proceedingJoinPoint);
			Thread.sleep(200);
			GjsAspect.logAfter(proceedingJoinPoint);
			assertEquals(1, GjsAspect.getWarnings());

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion recibida");
		}
	}

}
