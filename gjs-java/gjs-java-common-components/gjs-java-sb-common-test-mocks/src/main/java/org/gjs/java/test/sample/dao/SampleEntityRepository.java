package org.gjs.java.test.sample.dao;

import org.gjs.java.test.sample.model.SampleEntity;
import org.springframework.data.jpa.repository.JpaRepository;

public interface SampleEntityRepository extends JpaRepository<SampleEntity, Long> {

}
