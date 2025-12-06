package org.gjs.java.test.mock;

import java.io.IOException;

import org.gjs.java.idgenerator.IdGenerator;
import org.gjs.java.idgenerator.SequenceIdGenerator;
import org.springframework.core.io.Resource;

/**
 * The Class MockSimplePKRepository.
 *
 * Clase de datos de la librería Semilla
 *
 * Implementa un repositorio JPA de datos sencillo en memoria para cualquier
 * clase de objetos cuya clave primaria sea un Long.
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
 * @param <T> la clase de las entidad
 *
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
 *
 */
public class MockSimplePKRepository<T> extends MockRepository<T, Long> {

	/** The id generator. */
	protected IdGenerator<Long> idGenerator = new SequenceIdGenerator();

	/**
	 * Instantiates a new mock simple PK repository.
	 */
	public MockSimplePKRepository() {
	}

	/**
	 * Instantiates a new mock simple PK repository.
	 *
	 * @param resource the resource
	 * @throws IOException Signals that an I/O exception has occurred.
	 */
	public MockSimplePKRepository(Resource resource) throws IOException {
		super(resource);
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see org.gjs.java.test.mock.MockRepository#autogenerateId()
	 */

	@Override
	protected boolean autogenerateId() {
		return true;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see org.gjs.java.test.mock.MockRepository#getGeneratorId()
	 */

	@Override
	protected IdGenerator<Long> getGeneratorId() {
		return idGenerator;
	}

}
