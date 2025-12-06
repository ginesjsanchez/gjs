package org.gjs.java.jpa;

import java.util.Map;
import java.util.Map.Entry;

import org.gjs.java.enums.ManagedType;
import org.gjs.java.enums.PrimitiveType;
import org.gjs.java.types.DataObject;
import org.slf4j.LoggerFactory;
import org.springframework.data.repository.CrudRepository;
import org.springframework.util.CollectionUtils;

import lombok.Getter;
import lombok.Setter;

/**
 * Class CrudRepositoryWrapper.
 *
 * Clase de datos de la librería Semilla
 *
 * Clase que permite recubrir un repositorio con operativa CRUD.
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
 * @param <T>  la clase de objetos
 * @param <ID> la clase del identificador o clave primaria del objeto
 *
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
 *
 */

public class CrudRepositoryWrapper<T, ID> extends BaseRepositoryWrapper<T, ID> {

	/** The repository. */
	protected CrudRepository<T, ID> repository;

	@Getter
	@Setter
	/** The jpa dependencies. */
	protected Map<String, CrudRepositoryWrapper<?, ?>> dependencies;

	/**
	 * Instantiates a new crud repository wrapper.
	 *
	 * @param entity     the entity
	 * @param pk         the pk
	 * @param repository the repository
	 */
	public CrudRepositoryWrapper(Class<T> entity, Class<ID> pk, CrudRepository<T, ID> repository) {
		super(entity, pk, LoggerFactory.getLogger(CrudRepositoryWrapper.class));
		this.repository = repository;
	}

	/**
	 * Instantiates a new crud repository wrapper.
	 *
	 * @param entity     the entity
	 * @param pk         the pk
	 * @param repository the repository
	 * @param dataFile   the data file
	 */
	public CrudRepositoryWrapper(Class<T> entity, Class<ID> pk, CrudRepository<T, ID> repository, String dataFile) {
		super(entity, pk, dataFile, LoggerFactory.getLogger(CrudRepositoryWrapper.class));
		this.repository = repository;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see org.gjs.java.test.jpa.BaseRepositoryWrapper#getRepository()
	 */

	@Override
	public CrudRepository<T, ID> getRepository() {
		return repository;
	}

	/**
	 * Load dependencies.
	 */
	@Override
	protected void loadDependencies() {
		if (!CollectionUtils.isEmpty(dependencies)) {
			logger.debug("Loading dependencies (Total={})", dependencies.size());
			for (final Entry<String, CrudRepositoryWrapper<?, ?>> entry : dependencies.entrySet()) {
				final String field = entry.getKey();
				final CrudRepositoryWrapper<?, ?> dependency = entry.getValue();
				logger.debug("Loading dependencies for field {} of type {}", field, dependency.getClass());
				if (dependency.getRepository().count() == 0) {
					dependency.loadCsv();
				}
			}
		}
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see
	 * org.gjs.java.test.jpa.BaseRepositoryWrapper#resolveDependecies(org.gjs.java.
	 * types.DataObject, java.lang.Object)
	 */

	@Override
	protected void resolveDependecies(DataObject dataObj, T obj) {
		if (!CollectionUtils.isEmpty(dependencies)) {
			logger.debug("Completing dependency objects...");
			for (final Entry<String, CrudRepositoryWrapper<?, ?>> entry : dependencies.entrySet()) {
				final String field = entry.getKey();
				final CrudRepositoryWrapper<?, ?> dependency = entry.getValue();
				if (PrimitiveType.LONG.isSameClassType(dependency.getPk().getCanonicalName())) {
					@SuppressWarnings("unchecked")
					final CrudRepositoryWrapper<?, Long> simpleDependency = (CrudRepositoryWrapper<?, Long>) dependency;
					logger.debug("Find dependency for field {} of type {}", field, dependency.getEntity());
					assignDependencyFieldByLongId(dataObj, obj, field, simpleDependency);
				} else if (ManagedType.STRING.isSameType(dependency.getPk().getCanonicalName())) {
					@SuppressWarnings("unchecked")
					final CrudRepositoryWrapper<?, String> simpleDependency = (CrudRepositoryWrapper<?, String>) dependency;
					logger.debug("Find dependency for field {} of type {}", field, dependency.getEntity());
					assignDependencyFieldByStringId(dataObj, obj, field, simpleDependency);
				} else {
					logger.warn("Functionality not implemented for repositories with PK={}",
							dependency.getPk().getCanonicalName());
				}
			}
		}
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see
	 * org.gjs.java.test.jpa.BaseRepositoryWrapper#isFieldToTranslate(java.lang.
	 * String)
	 */

	@Override
	protected boolean isFieldToTranslate(String field) {
		boolean translate = true;
		if (!CollectionUtils.isEmpty(dependencies)) {
			translate = !dependencies.containsKey(field);
		}
		return translate;
	}

}
