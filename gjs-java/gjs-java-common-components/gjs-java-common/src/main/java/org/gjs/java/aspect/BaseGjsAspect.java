package org.gjs.java.aspect;

import java.util.Objects;

import org.apache.commons.lang3.ArrayUtils;
import org.aspectj.lang.JoinPoint;
import org.gjs.java.dto.AuditDto;
import org.gjs.java.dto.StatisticsDto;
import org.gjs.java.enums.AuditLogType;
import org.gjs.java.log.LogManager;
import org.gjs.java.singleton.GlobalObjectsManager;
import org.gjs.java.util.ConditionUtils;
import org.gjs.java.util.MDCUtils;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The Class BaseGjsAspect.
 *
 * Clase abstracta de datos de la librería Semilla
 *
 * Clase base para utilizar en aspectos que quieran recubir los métodos, es
 * decir, que necesiten actuar al inicio y al final de un método, termine como
 * termine (retornao normal o excepción).
 *
 * --------------------------------------------------------------------------------------------------------------------
 * Este software es propiedad del Ministerio del Interior CETSE - 2025
 *
 * Queda estrictamente prohibido el uso de programas informáticos sin la
 * correspondiente licencia en los activos de la SES. Los programas informáticos
 * propiedad de la SES están protegidos por la propiedad intelectual, y por
 * tanto está estrictamente prohibida su reproducción, modificación, cesión o
 * comunicación sin la debida autorización. Queda estrictamente prohibido el
 * uso, reproducción, cesión, transformación o comunicación pública de cualquier
 * otro tipo de obra o invención protegida por la propiedad intelectual sin la
 * debida autorización.
 *
 * Subdirección General de Sistemas de la Información y Comunicaciones para la
 * Seguridad Ministerio del Interior Gobierno de España
 * --------------------------------------------------------------------------------------------------------------------
 *
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
 *
 */
public abstract class BaseGjsAspect extends LogManager {

	/**
	 * Gets the logger.
	 *
	 * @param joinPoint the join point
	 * @return the logger
	 */
	protected Logger getLogger(JoinPoint joinPoint) {
		return LoggerFactory.getLogger(joinPoint.getTarget().getClass());
	}

	/**
	 * Gets the logger.
	 *
	 * @param auditDto the audit dto
	 * @return the logger
	 */
	protected Logger getLogger(AuditDto auditDto) {
		return LoggerFactory.getLogger(auditDto.getModule());
	}

	/**
	 * Gets the audit info.
	 *
	 * @param joinPoint the join point
	 * @return the audit info
	 */
	protected AuditDto getAuditInfo(JoinPoint joinPoint) {
		final String method = joinPoint.getSignature().getName();
		final String clazz = joinPoint.getTarget().getClass().getCanonicalName();
		final String key = String.format("%s:%s", clazz, method);
		// return (AuditDto) GlobalObjectsManager.getInstance().load(key);
		return (AuditDto) MDCUtils.load(key, AuditDto.class);
	}

	/**
	 * Critical time.
	 *
	 * @return the long
	 */
	protected long criticalTime() {
		return 0;
	}

	/**
	 * When time warn.
	 *
	 * @param auditDto the audit dto
	 */
	protected void whenTimeWarn(AuditDto auditDto) {
	}

	/**
	 * Format log.
	 *
	 * @param joinPoint the join point
	 * @return the string
	 */
	protected String formatLog(JoinPoint joinPoint) {
		return formatLog(joinPoint, null);
	}

	/**
	 * Format log.
	 *
	 * @param joinPoint the join point
	 * @param type      the type
	 * @return the string
	 */
	protected String formatLog(JoinPoint joinPoint, AuditLogType type) {
		return formatLog(joinPoint, type, false);
	}

	/**
	 * Format log.
	 *
	 * @param joinPoint the join point
	 * @param type      the type
	 * @param skip      the skip
	 * @return the string
	 */
	protected String formatLog(JoinPoint joinPoint, AuditLogType type, boolean skip) {
		final StringBuilder info = new StringBuilder(1024);
		final String method = joinPoint.getSignature().getName();
		final String clazz = joinPoint.getTarget().getClass().getCanonicalName();
		final Object[] args = joinPoint.getArgs();
		info.append('[').append(clazz).append("][").append(method).append(']');
		if (Objects.nonNull(type)) {
			info.append('[').append(type.toString()).append(']');
			if (AuditLogType.BEGIN.equals(type)) {
				final AuditDto auditDto = new AuditDto(clazz, method);
				MDCUtils.save(auditDto.getKey(), auditDto);
				// GlobalObjectsManager.getInstance().save(auditDto.getKey(), auditDto);
				info.append("[Args=").append(ArrayUtils.toString(args)).append(']');
			} else if (AuditLogType.END.equals(type)) {
				AuditDto auditDto = new AuditDto(clazz, method);
				// final AuditDto auditDto = (AuditDto)
				// GlobalObjectsManager.getInstance().load(key);
				auditDto = (AuditDto) MDCUtils.load(auditDto.getKey(), AuditDto.class);
				if (Objects.nonNull(auditDto)) {
					auditDto.end();
					info.append("[Time=").append(auditDto.getTime()).append(" ms]");
					// GlobalObjectsManager.getInstance().remove(key);
					MDCUtils.remove(auditDto.getKey());
					additionalEndTasks(auditDto, skip);
				}
			} else if (AuditLogType.RETURNS.equals(type)) {
				info.append("[Returned={}]");
			} else if (AuditLogType.THROWS.equals(type)) {
				info.append("[Throwed={}: {}]");
			}
		}
		return info.toString();
	}

	/**
	 * Additional end tasks.
	 *
	 * @param auditDto the audit dto
	 * @param skip     the skip
	 */
	protected void additionalEndTasks(AuditDto auditDto, boolean skip) {
		final long criticalTime = criticalTime();
		if (ConditionUtils.allAreTrue((criticalTime > 0), (criticalTime <= auditDto.getTime()))) {
			whenTimeWarn(auditDto);
		}
		if (!skip) {
			StatisticsDto statisticsDto = (StatisticsDto) GlobalObjectsManager.getInstance()
					.load(auditDto.getCommonKey());
			if (Objects.isNull(statisticsDto)) {
				statisticsDto = new StatisticsDto(auditDto.getModule(), auditDto.getPrimitive());
			}
			statisticsDto.addMeassure(auditDto);
			GlobalObjectsManager.getInstance().save(statisticsDto.getKey(), statisticsDto);
		}
	}

}
