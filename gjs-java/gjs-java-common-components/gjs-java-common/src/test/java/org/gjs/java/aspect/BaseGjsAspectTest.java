package org.gjs.java.aspect;

import static org.junit.jupiter.api.Assertions.fail;

import java.util.ArrayList;
import java.util.List;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.Signature;
import org.aspectj.lang.reflect.SourceLocation;
import org.gjs.java.enums.AuditLogType;
import org.gjs.java.test.BaseUnitTest;
import org.gjs.java.test.samples.aspect.TargetAspectSample;
import org.junit.jupiter.api.Test;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.Mockito;

public class BaseGjsAspectTest extends BaseUnitTest<BaseGjsAspect> {

	class TestGjsAspect extends BaseGjsAspect {

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
	private TestGjsAspect gjsAspect;

	private static TargetAspectSample targetAspectSample;

	@Override
	protected void initialize() throws Exception {
		gjsAspect = new TestGjsAspect();
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

			gjsAspect.log(proceedingJoinPoint);
			gjsAspect.logBefore(proceedingJoinPoint);
			gjsAspect.logAfter(proceedingJoinPoint);
			gjsAspect.logReturn(proceedingJoinPoint, "Result");
			gjsAspect.logThrow(proceedingJoinPoint, new RuntimeException("Test"));

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion recibida");
		}
	}

	@Test
	public void testGjsAspect2() {
		try {
			final List<Object> listArgs = new ArrayList<>();
			listArgs.add("Param1");
			listArgs.add("Param2");
			final Object args[] = listArgs.toArray(new Object[listArgs.size()]);
			final String signatureName = "Run";
			Mockito.when(proceedingJoinPoint.getTarget()).thenReturn(targetAspectSample);
			Mockito.when(proceedingJoinPoint.getArgs()).thenReturn(args);
			Mockito.when(proceedingJoinPoint.getSignature()).thenReturn(signature);
			Mockito.when(signature.getName()).thenReturn(signatureName);

			gjsAspect.logBefore(proceedingJoinPoint);
			gjsAspect.logAfter(proceedingJoinPoint);
			gjsAspect.logReturn(proceedingJoinPoint, "Result");
			gjsAspect.logThrow(proceedingJoinPoint, new RuntimeException("Test"));

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion recibida");
		}
	}

}
