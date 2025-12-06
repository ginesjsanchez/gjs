package org.gjs.java.test;

import java.util.Map;
import java.util.Objects;

import org.gjs.java.common.ConditionUtils;
import org.gjs.java.jpa.JpaRepositoryWrapper;
import org.springframework.core.io.ClassPathResource;
import org.springframework.data.jpa.repository.JpaRepository;

/**
 * The Class AbstractRepositoryUnitTest.
 *
 * Clase abstracta funcional de la librería Semilla
 *
 * Clase abstracta base para todos los test unitarios de repositorios JPA de la
 * librería Semilla
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
 * @param <T>  el repositorio JPA
 * @param <E>  la entidad JPA
 * @param <PK> la clave primaria de la entidad JPA
 *
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
 *
 */
public abstract class AbstractRepositoryUnitTest<T, E, PK> extends AbstractPersistenceUnitTest<T> {

	/** The pk clazz. */
	private final Class<PK> pkClazz;

	/** The entity clazz. */
	private final Class<E> entityClazz;

	/** The repository wrapper. */
	private JpaRepositoryWrapper<E, PK> repositoryWrapper;

	/** The show data. */
	protected boolean showData;

	/**
	 * Instantiates a new abstract repository unit test.
	 *
	 * @param testClazz   the test clazz
	 * @param entityClazz the entity clazz
	 * @param pkClazz     the pk clazz
	 */
	public AbstractRepositoryUnitTest(Class<T> testClazz, Class<E> entityClazz, Class<PK> pkClazz) {
		super(testClazz);
		this.entityClazz = entityClazz;
		this.pkClazz = pkClazz;
		this.showData = false;
	}

	/**
	 * Gets the entity clazz.
	 *
	 * @return the entity clazz
	 */
	protected Class<E> getEntityClazz() {
		return entityClazz;
	}

	/**
	 * Gets the PK clazz.
	 *
	 * @return the PK clazz
	 */
	protected Class<PK> getPKClazz() {
		return pkClazz;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see org.gjs.java.test.BaseUnitTest#isValid()
	 */

	@Override
	public boolean isValid() {
		return ConditionUtils.allAreTrue(super.isValid(), Objects.nonNull(entityClazz), Objects.nonNull(pkClazz));
	}

	/**
	 * Gets the repository.
	 *
	 * @return the repository
	 */
	protected abstract JpaRepository<E, PK> getRepository();

	/**
	 * Gets the resource path.
	 *
	 * @return the resource path
	 */
	protected abstract String getResourcePath();

	/**
	 * Gets the immutable id.
	 *
	 * @param index the index
	 * @return the immutable id
	 */
	protected abstract PK getImmutableId(int index);

	/**
	 * Gets the non existent id.
	 *
	 * @return the non existent id
	 */
	protected abstract PK getNonExistentId();

	/**
	 * Checks if is expected.
	 *
	 * @param id the id
	 * @return true, if is expected
	 */
	protected abstract boolean isExpected(PK id);

	/**
	 * Gets the repository wrapper.
	 *
	 * @return the repository wrapper
	 */
	protected JpaRepositoryWrapper<E, PK> getRepositoryWrapper() {
		return repositoryWrapper;
	}

	/**
	 * Gets the dependencies.
	 *
	 * @return the dependencies
	 */
	protected Map<String, JpaRepositoryWrapper<?, ?>> getDependencies() {
		return null;
	}

	/**
	 * Gets the field correspondencies.
	 *
	 * @return the field correspondencies
	 */
	protected Map<String, String> getFieldCorrespondencies() {
		return null;
	}

	/**
	 * Prepare test data.
	 *
	 * @throws Exception the exception
	 */
	protected void prepareTestData() throws Exception {
	}

	/**
	 * Prepare aditional test data.
	 *
	 * @throws Exception the exception
	 */
	protected void prepareAditionalTestData() throws Exception {
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see org.gjs.java.test.AbstractDataObjectUnitTest#loadTestData()
	 */

	@Override
	protected long loadTestData() throws Exception {
		prepareTestData();

		repositoryWrapper = new JpaRepositoryWrapper<>(getEntityClazz(), getPKClazz(), getRepository());
		repositoryWrapper.setJpaDependencies(getDependencies());
		repositoryWrapper.setFieldCorrespondencies(getFieldCorrespondencies());
		// TODO : AQui habria que inicializar todos?
		repositoryWrapper.getRepository().deleteAll();
		// ------
		repositoryWrapper.loadCsv(new ClassPathResource(getResourcePath()));
		prepareAditionalTestData();
		return (int) repositoryWrapper.getRepository().count();
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see org.gjs.java.test.AbstractDataObjectUnitTest#postLoadTestData()
	 */

	@Override
	protected void postLoadTestData() {
		if (showData) {
			logger.debug("=".repeat(50));
			logger.debug("Data loaded in repository:");
			for (final E entity : repositoryWrapper.getRepository().findAll()) {
				logger.debug("-".repeat(50));
				logger.debug(entity.toString());
			}
			logger.debug("=".repeat(50));
		}
	}

}
